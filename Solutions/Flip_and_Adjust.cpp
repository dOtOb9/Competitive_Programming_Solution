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
    bool unite(l x, l y) {
        l rx = find(x);
        l ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        size[rx] += size[ry];
        if (rank[rx] == rank[ry]) rank[rx]++;

        tree_count--;

        return true;
    }
    
    bool same(l x, l y) {
        return find(x) == find(y);
    }
    
    l getSize(l x) {
        return size[find(x)];
    }
};

int main() {
    l n,s;cin >> n >> s;
    vector<l> a(n),b(n);
    r(i, n) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(n+1, vector<bool>(s+1));
    dp[0][0] = true;

    r(i, n) {
        r(j, s+1) {
            if (j-a[i] >= 0) dp[i+1][j] = dp[i+1][j] || dp[i][j-a[i]];
            if (j-b[i] >= 0) dp[i+1][j] = dp[i+1][j] || dp[i][j-b[i]];
        }
    }

    if (!dp[n][s]) {
        cout << "No" << endl;
        return 0;
    } else cout << "Yes" << endl;

    l res = s;
    string ans;
    r(i, n) {
        if (dp[n-i-1][res - a[n-1-i]]) {
            ans += "H";
            res -= a[n-1-i];
            continue;
        } else {
            ans += "T";
            res -= b[n-1-i];
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}