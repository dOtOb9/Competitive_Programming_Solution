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

using namespace std;
using l = long long;
using ul = unsigned long long;

const int inf =  2147483647;         // 2e9     1 << 30
const l INF = 9223372036854775807;  // 9e18    1LL << 60

#define r(i, n) for (l i = 0; i < n; ++i)
#define r1(i, n) for (l i = 1; i < n; ++i)
#define r0(i) for (l i = -1; i < 2; ++i)
#define pll pair<l, l>


struct UnionFind {
    vector<int> parent, rank, size;
    int tree_count;
    
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1), tree_count(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find(l x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);  // パス圧縮
    }
    bool unite(l x, l y) {
        int rx = find(x);
        int ry = find(y);
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
    
    int getSize(int x) {
        return size[find(x)];
    }
};


int main() {
    l n,m;cin>>n>>m;

    vector<vector<l>> edge;
    
    r(i, m) {
        l a,b;cin>>a>>b;--a;--b;

        edge.push_back({a,b});
    }

    l ans=0;

    r(i, m) {
        UnionFind uf(n);

        r(j, m) {
            if (i==j) continue;

            uf.unite(edge[j][0], edge[j][1]);
        }

        if (uf.getSize(0)!=n) ++ans;
    }
    cout<<ans<<endl;
}