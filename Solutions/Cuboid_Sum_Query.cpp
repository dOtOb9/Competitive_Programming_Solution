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
    l n;cin>>n;

    vector<vector<vector<l>>> a(n+1, vector<vector<l>>(n+1, vector<l>(n+1)));

    r(i, n) r(j, n) r(k, n) {
        cin >> a[i+1][j+1][k+1];
    }

    
    r(i, n) r(j, n) r(k, n) {
        a[i+1][j+1][k+1] += a[i+1][j][k+1] + a[i+1][j+1][k] - a[i+1][j][k];
        a[i+1][j+1][k+1] += a[i][j+1][k+1] - a[i][j][k+1] - a[i][j+1][k] + a[i][j][k];
    }
    
    l Q;cin>>Q;

    r(_, Q) {
        l lx, rx, ly, ry, lz, rz;cin >> lx >> rx >> ly >> ry >> lz >> rz;--lx;--ly;--lz;

        l ans = a[rx][ry][rz];

        ans -= a[rx][ly][rz] + a[rx][ry][lz] + - a[rx][ly][lz];
        ans -= a[lx][ry][rz] - a[lx][ly][rz] - a[lx][ry][lz] + a[lx][ly][lz];

        cout << ans << endl;
    }
}