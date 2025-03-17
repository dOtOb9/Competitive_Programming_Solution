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
    l n, K;cin>>n>>K;

    vector<l> c(n), ri(n);

    r(i,n) cin>>c[i]>>ri[i];

    vector<vector<l>> roads(n);

    r(i, K) {
        l a,b;cin>>a>>b;--a;--b;

        roads[a].push_back(b);
        roads[b].push_back(a);
    }

    vector<vector<pll>> taxi(n);

    r(i, n) {
        vector<l> d(n, INF);

        d[i]=0;

        queue<l> q;q.push(i);

        while(!q.empty()) {
            auto u = q.front();q.pop();

            for (auto v : roads[u]) {
                if (d[v]==INF) {
                    d[v]=d[u]+1;

                    if (d[v]<=ri[i]) {
                        q.push(v);
                        taxi[i].push_back({c[i], v});
                    }
                }
            }
        }
    }

    vector<l> mincost(n, INF);

    mincost[0]=0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;pq.push({0, 0});

    while(!pq.empty()) {
        auto [cost, u] = pq.top();pq.pop();

        if (mincost[u] < cost) continue;

        for (auto [c, v] : taxi[u]) {
            if (cost + c < mincost[v]) {
                mincost[v] = cost + c;

                pq.push({mincost[v], v});
            }
        }
    }

    cout<<mincost[n-1]<<endl;
}