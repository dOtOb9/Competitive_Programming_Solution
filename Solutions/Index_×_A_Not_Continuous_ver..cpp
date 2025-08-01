#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <functional>
#include <stack>
#include <numeric>

using namespace std;
using l = long long;
using ul = unsigned long long;

const int inf =  2147483647;         // 2e9     1 << 30
const l INF = 9223372036854775807;  // 9e18    1LL << 60

#define r(i, n) for (l i = 0; i < n; ++i)
#define r1(i, n) for (l i = 1; i < n; ++i)
#define r0(i) for (l i = -1; i < 2; ++i)
#define pll pair<l, l>

void YesNo(bool s=false) {
    if (s) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

struct UnionFind {
    vector<l> parent, rank, size;
    l tree_count;

    UnionFind(l n) : parent(n), rank(n, 0), size(n, 1), tree_count(n) {
        for (l i = 0; i < n; i++) parent[i] = i;
    }
    
    l find(l x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);  // パス圧縮
    }
    bool unite(pll xy) {
        l rx = find(xy.first);
        l ry = find(xy.second);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        size[rx] += size[ry];
        if (rank[rx] == rank[ry]) rank[rx]++;

        tree_count--;

        return true;
    }
    
    bool same(pll xy) {
        return find(xy.first) == find(xy.second);
    }
    
    l getSize(l x) {
        return size[find(x)];
    }
};

int main() {
    l n, m;cin >> n >> m;
    vector<l> a(n);

    r(i, n) cin >> a[i];

    vector<vector<l>> dp(n+1, vector<l>(m+1, -INF));

    for (l i = 0; i <= n; ++i) {
        dp[i][0] = 0;
    }

    r1(i, n+1) {
        r1(j, m+1) {
            l not_select = dp[i-1][j];

            // A[i-1] を選ぶ場合
            // ただし、j-1個目までが選ばれていない（-INF）場合は選べない
            l select = -INF;
            if (dp[i-1][j-1] != -INF) { // 遷移元が有効な値の場合のみ計算
                select = dp[i-1][j-1] + j * a[i-1];
            }
            
            dp[i][j] = max(not_select, select);
        }
    }

    cout << dp[n][m] << endl;
}