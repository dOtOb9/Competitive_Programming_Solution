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
using ll = long long;
using ull = unsigned long long;

const int inf = 1 << 30;
const ll INF = 1LL << 60;

#define rep(i, n) for (int i = 0; i < n; ++i)


int main () {
    int n;
    cin >> n;

    vector<vector<int>> v(n);

    rep(i, n) {
        int u, k;
        cin >> u >> k;
        
        --u;

        rep(j, k) {
            int V;
            cin >> V;

            v[u].push_back(--V);
        }
    }

    vector<int> ans(n, -1);

    queue<int> q;

    q.push(0);
    ans[0] = 0;
    
    while(!q.empty()) {
        int cu = q.front(); q.pop();

        int len = v[cu].size();

        rep(i, len) {
            if (ans[v[cu][i]] != -1) continue;
            ans[v[cu][i]] = ans[cu] + 1;

            q.push(v[cu][i]);
        }
    }

    rep(i, n) cout << i + 1 << " " << ans[i] << endl;
}
