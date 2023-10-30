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
    int q;
    cin >> q;

    rep(i, q) {
        string x, y;
        cin >> x >> y;

        int xs = x.size();
        int ys = y.size();

        vector<vector<int>> dp(ys + 1, vector<int> (xs + 1, 0));

        rep(i, ys) {
            rep(j, xs) {
                if (x[j] == y[i]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        cout << dp[ys][xs] << endl;
    }
}
