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
    l h, w, D;cin>>h>>w>>D;

    vector<string> f(h);

    r(i, h) cin>>f[i];

    vector<vector<l>> d(h, vector<l> (w, INF));

    queue<pll> q;

    r(i, h) r(j, w) {
        if (f[i][j]=='H') {
            d[i][j]=0;
            q.push({i,j});
        }
    }

    while(!q.empty()) {
        auto [y,x] = q.front();q.pop();

        r0(dy)r0(dx) {
            if (dy!=0 && dx!=0) continue;

            l ny=y+dy, nx=x+dx;

            if (ny<0 || ny>=h || nx<0 || nx>=w) continue;

            if (d[ny][nx]==INF && f[ny][nx]!='#') {
                d[ny][nx]=d[y][x]+1;

                q.push({ny,nx});
            }
        }
    }

    l ans=0;

    r(i, h)r(j,w) if (d[i][j] <= D) ++ans;

    cout<<ans<<endl;
}