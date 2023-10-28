#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;
using ll = long long;
using ull = unsigned long long;

const int inf = 1 << 30;
const ll INF = 1LL << 60;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main () {
    int n, m;
    cin >> n >> m;
    vector<int> c(m);

    rep(i, m) cin >> c[i];

    vector<int> dp(n + 1, 1e5);
    dp[0] = 0;

    rep(i, m) {
        rep(j, n + 1) {
            if (j >= c[i]) dp[j] = min(dp[j], dp[j - c[i]] + 1);
        }
    }

    cout << dp[n] << endl;
}
