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
    l n;cin >> n;
    l amin = 0;
    l amax = 0;

    vector<bool> color(8);

    l cnt = 0;

    r(i, n) {
        l a;cin >> a;

        if (a < 400) color[0] = true;
        else if (a < 800) color[1] = true;
        else if (a < 1200) color[2] = true;
        else if (a < 1600) color[3] = true;
        else if (a < 2000) color[4] = true;
        else if (a < 2400) color[5] = true;
        else if (a < 2800) color[6] = true;
        else if (a < 3200) color[7] = true;
        else {
            ++cnt;
        }
    }
    
    r(i, 8) if (color[i]) {
        ++amin;
        ++amax;
    }

    if (cnt > 0) amin = max(1LL, amin);
    amax = min(8LL, amax+cnt);
    cout << amin << " " << amax << endl;
}