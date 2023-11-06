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

const int inf = 2147483647;         // 1 << 30, 2e9
const ll INF = 9223372036854775807; // 1 << 60, 9e18

#define rep(i, n) for (int i = 0; i < n; ++i)
#define pii pair<int, int>

int main () {
    int v, e;
    cin >> v >> e;

    vector<vector<vector<ll>>> dp(v + 1, vector<vector<ll>> (v, vector<ll> (v, INF)));

    rep(i, v) rep(j, v) {
        dp[i][j][j] = 0;
    }

    rep(i, e) {
        int s, t, d;
        cin >> s >> t >> d;

        dp[0][s][t] = d;
    }

    rep(i, v) rep(j, v) rep(k, v) {
        if (dp[i][j][i] == INF || dp[i][i][k] == INF) dp[i + 1][j][k] = dp[i][j][k];
        else dp[i + 1][j][k] = min(dp[i][j][k], dp[i][j][i] + dp[i][i][k]);
    }


    rep(i,v) rep(j, v) {
        if (dp[v][i][j] == INF || dp[v][j][i] == INF) continue;

        if (dp[v][i][j] + dp[v][j][i] < 0) {
            cout << "NEGATIVE CYCLE" << endl;
            return 0;
        }
    }


    rep(i, v) {
        rep(j, v) {
        if (dp[v][i][j] == INF) cout << "INF";
        else cout << dp[v][i][j];

        cout << " \n"[j == v - 1];
        }
    }
}
