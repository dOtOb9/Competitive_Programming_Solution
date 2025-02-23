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


void test() {
    l n;cin>>n;
    if (n==0) exit(0);

    vector<vector<double>> cells;

    r(i, n) {
        double x,y, z, r; cin>>x>>y>>z>>r;

        cells.push_back({x,y, z, r});
    }

    vector<vector<double>> ways;

    r(i,n) for (l j=i+1; j<n;++j) {
        double x=i, y=j;

        double dist = sqrt(pow(cells[i][0]-cells[j][0], 2) + pow(cells[i][1]-cells[j][1], 2) + pow(cells[i][2]-cells[j][2], 2)) - abs(cells[i][3]+cells[j][3]);

        double d = max(dist, 0.);

        ways.push_back({d, x, y});
    }

    UnionFind uf(n);

    sort(ways.begin(), ways.end());

    double ans=0;

    for (auto way : ways) {
        if (uf.unite(way[1], way[2])) {
            ans+=way[0];
        }
    }

    printf("%.3f\n", ans);
}

int main() {
    while(true ) test();
}