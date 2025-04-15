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

void nans(l ans) {
    if (ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
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


void demo() {
    l w, h;cin>>w>>h;

    if (w==0 && h==0) exit(0);

    vector<vector<bool>> f(h, vector<bool> (w, false));

    r(i, h) r(j, w) {
        l c;cin>>c;

        if (c==1) f[i][j]=true;
    }

    vector<vector<bool>> vs(h, vector<bool>(w, false));

    function<void(l,l)> dfs=[&](l y, l x) {
        vs[y][x]=true;

        r0(dy)r0(dx) {
            l ny=dy+y, nx=dx+x;

            if (ny<0 || ny>=h || nx<0 || nx>=w) continue;

            if (vs[ny][nx]) continue;

            if (f[ny][nx]) {
                dfs(ny,nx);
            }
        }
    };

    l ans=0;

    r(i, h) r(j, w) {
        if (!vs[i][j] && f[i][j]) {
            ++ans;

            dfs(i, j);
        }
    }

    cout<<ans<<endl;
}

int main() {
    while (true) demo();
}