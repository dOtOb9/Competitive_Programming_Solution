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


int main() {
    l n, m, K, s;cin>>n>>m>>K>>s;

    l P, Q;cin>>P>>Q;

    vector<l> c(K);

    r(i,K) cin>>c[i];

    vector<vector<l>> g(n);

    r(i, m) {
        l a, b;cin>>a>>b;--a;--b;

        g[a].push_back(b);
        g[b].push_back(a);
    }


    vector<bool> danger(n, false);

    r(i,K) {
        queue<l> q;q.push(c[i]-1);

        vector<l> d(n, INF);

        d[c[i]-1]=0;

        while(!q.empty()) {
            auto u=q.front();q.pop();

            for (auto v : g[u]) {
                if (d[v]==INF) {
                    d[v]=d[u]+1;

                    q.push(v);
                }
            }
        }

        r(j,n) if (d[j]<=s) danger[j]=true;
    }

    vector<vector<pll>> roads(n);

    r(u, n) {

        bool flag=false;

        r(i,K) {
            if (c[i]-1==u) flag=true;
        }

        if (flag) continue;

        for(auto v : g[u]) {
            if (danger[v]) {

                roads[u].push_back({Q, v});
            } else {
                roads[u].push_back({P, v});
            }
        }
    }

    priority_queue<pll, vector<pll>, greater<pll>> q;q.push({0,0});

    vector<l> mincost(n, INF);

    mincost[0]=0;

    while(!q.empty()) {
        auto [cost, u] = q.top();q.pop();

        if (mincost[u]<cost) continue;

        for(auto [c, v] : roads[u]) {

            if (v==n-1) {
                cout<<mincost[u]<<endl;

                return 0;
            }

            if (mincost[v] > cost+c) {
                mincost[v]=cost+c;

                q.push({mincost[v], v});
            }
        }
    }
}