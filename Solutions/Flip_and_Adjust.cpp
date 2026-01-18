#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

using mint = atcoder::modint998244353;
using l = long long;

const int inf = 2147483647;
const l INF = 9223372036854775807;

#define rep(i, n) for (l i = 0; i < n; ++i)
#define r1(i, n) for (l i = 1; i < n; ++i)

void YesNo(bool s = false) {
    if (s) cout << "Yes" << endl;
    else cout << "No" << endl;
}

int main() {
    l n, s; cin >> n >> s;
    vector<l> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];

    // dp[i][j]: i枚目まで決めて合計がjにできるか
    vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
    dp[0][0] = true;

    rep(i, n) {
        rep(j, s + 1) {
            if (!dp[i][j]) continue;
            if (j + a[i] <= s) dp[i+1][j + a[i]] = true;
            if (j + b[i] <= s) dp[i+1][j + b[i]] = true;
        }
    }

    if (!dp[n][s]) {
        YesNo(false);
        return 0;
    }

    YesNo(true);
    string ans = "";
    l res = s;
    // 復元処理：後ろから順にどちらを選んだか確定させる
    for (int i = n - 1; i >= 0; --i) {
        if (res >= a[i] && dp[i][res - a[i]]) {
            ans += "H";
            res -= a[i];
        } else {
            ans += "T";
            res -= b[i];
        }
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}