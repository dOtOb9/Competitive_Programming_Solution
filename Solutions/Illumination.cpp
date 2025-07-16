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
    l w, h;cin >> w >> h;

    vector<vector<bool>> f(h+2, vector<bool>(w+2));

    r(i, h) r(j, w) {
        l a;cin >> a;

        f[i+1][j+1] = a==1;
    }

    vector<vector<pll>> d(2);

    d[1].push_back({1, -1});
    d[1].push_back({1, 0});
    d[1].push_back({1, 1});
    d[1].push_back({0, 1});
    d[1].push_back({-1, 0});
    d[1].push_back({0, -1});

    d[0].push_back({-1, -1});
    d[0].push_back({0, -1});
    d[0].push_back({1, 0});
    d[0].push_back({0, 1});
    d[0].push_back({-1, 1});
    d[0].push_back({-1, 0});

    vector<vector<bool>> vs(h+2, vector<bool>(w+2));

    vs[0][0] = true;

    queue<pll> q;q.push({0,0});

    while(!q.empty()) {
        auto [x, y] = q.front();q.pop();

        for (auto [dx, dy] : d[y % 2]) {
            l ny = y + dy, nx = x + dx;

            if (ny < 0 || ny >= h+2 || nx < 0 || nx >= w+2) continue;

            if (vs[ny][nx] || f[ny][nx]) continue;

            vs[ny][nx] = true;

            q.push({nx, ny});
        }
    }

    l ans = 0;

    r(i, h+2) r(j, w+2) {
        if (f[i][j]) {
            r(k, 6) {
                l y = i + d[i % 2][k].second, x = j + d[i % 2][k].first;
                if (y < 0 || y >= h+2 || x < 0 || x >= w+2) continue;
                if (vs[y][x]) {
                    ++ans;
                }
            }
        }
    }

    cout << ans << endl;
}