#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using mint = modint998244353;
using l = long long;
using ul = unsigned long long;

const int inf = 2147483647;        // 2e9     1 << 30
const l INF = 9223372036854775807; // 9e18    1LL << 60

#define r(i, n) for (l i = 0; i < n; ++i)
#define r1(i, n) for (l i = 1; i < n; ++i)
#define r0(i) for (l i = -1; i < 2; ++i)
#define pll pair<l, l>

void YesNo(bool s = false)
{
    if (s)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

//Era(n)を呼んだ後、isprime[i]=iが素数かどうか　となっている。
vector < bool > isprime;
//返り値は素数のリスト。
vector < l > Era(int n) {
	isprime.resize(n, true);
	vector < l > res;
	isprime[0] = false;
	isprime[1] = false;
	for(l i = 2; i < n; ++i) isprime[i] = true;
	for(l i = 2; i < n; ++i) {
		if(isprime[i]) {
			res.push_back(i);
			for(l j = i * 2; j < n; j += i) isprime[j] = false;
		}
	}
	return res;
}

//==================================================================================

int main() {
    l n;cin >> n;
    vector<l> a(n);
    r(i, n) cin >> a[i];
    vector<l> b(n);
    r(i, n) cin >> b[i];

    vector<vector<mint>> dp(3010, vector<mint>(3010));

    dp[0][0] = 1;

    r(i, n+1) {
        r(j, 3000) {
            dp[i][j+1] += dp[i][j];
        }

        if (i < n) for (l c = a[i]; c <= b[i]; ++c) {
            dp[i+1][c] += dp[i][c];
        }
    }

    cout << dp[n][3000].val() << endl;
}