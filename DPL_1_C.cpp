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
    int n, max_w;
    cin >> n >> max_w;

    vector<int> v(n), w(n);

    rep(i, n) cin >> v[i] >> w[i];

    vector<vector<int>> dp(n + 1, vector<int> (max_w + 1, -1));

    rep(i, max_w) dp[0][i] = 0;

    rep(i, n) {
        rep(j, max_w + 1) {
            if (j >= w[i]) dp[i + 1][j] = max(dp[i + 1][j - w[i]] + v[i], dp[i][j]);
            else dp[i + 1][j] = dp[i][j];
        }
    }

    cout << dp[n][max_w] << endl; 
}
