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
    l n1, n2, m;cin >> n1 >> n2 >> m;

    vector<vector<l>> g(n1+n2);

    r(i, m) {
        l a,b;cin >> a >>b;--a;--b;

        g[a].push_back(b);
        g[b].push_back(a);
    }

    l ans = 1;

    r(i, 2) {
        l x;
        if (i==0) x = 0;
        else x = n1+n2-1;

        queue<l> q;q.push(x);

        vector<l> d(n1+n2, INF);

        d[x] = 0;

        l res = 0;

        while (!q.empty()) {
            l u = q.front();q.pop();

            for (l v : g[u]) {
                if (d[v] == INF) {
                    d[v] = d[u]+1;

                    res = max(res, d[v]);

                    q.push(v);
                }
            }
        }

        ans += res;
    }

    cout << ans << endl;
}