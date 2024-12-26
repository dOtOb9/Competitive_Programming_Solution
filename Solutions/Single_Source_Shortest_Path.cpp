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
    l V, E, r;cin>>V>>E>>r;

    vector<vector<pll>> g(V);

    r(i, E) {
        l s, t, d;cin>>s>>t>>d;

        g[s].push_back({t, d});
    }

    priority_queue<pll, vector<pll>, greater<pll>> q;q.push({0, r});

    vector<l> mincost(V, INF);

    mincost[r]=0;

    while(!q.empty()) {
        auto [cost, u] = q.top();q.pop();

        if (cost>mincost[u]) continue;

        r(i, g[u].size()) {
            auto [v, c] = g[u][i];

            if (mincost[v] > mincost[u] + c) {
                mincost[v] = mincost[u] + c;

                q.push({mincost[v], v});
            }
        }
    }

    r(i, V) {
        if (mincost[i]==INF) cout<<"INF"<<endl;
        else cout<<mincost[i]<<endl;
    }
}