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
    l n;cin >> n;

    vector<vector<bool>> f(2010, vector<bool>(2010));

    vector<vector<bool>> vs(2010, vector<bool>(2010));

    r(i, n) {
        l x, y;cin >> x >> y;
        f[y+1000][x+1000] = true;
    }

    vector<pll> edge(6);

    edge[0] = {-1, -1};
    edge[1] = {-1, 0};
    edge[2] = {0, -1};
    edge[3] = {0, 1};
    edge[4] = {1, 0};
    edge[5] = {1, 1};

    function<void(l, l)> dfs=[&] (l y, l x) {
        vs[y][x] = true;

        for (auto [dy, dx] : edge) {
            l ny = y + dy, nx = x + dx;

            if (ny < 0 || nx < 0) continue;

            if (vs[ny][nx] || !f[ny][nx]) continue;

            dfs(ny, nx);
        }
    };

    l ans = 0;

    r(i, 2010) r(j, 2010) {
        if (vs[i][j] || !f[i][j]) continue;

        ++ans;
        dfs(i, j);
    }

    cout << ans << endl;
}