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
#define re(i, n) for (l i = n-1; i >= 0; --i)
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
	l m, n;cin >> m >> n;
	vector<vector<bool>> f(n, vector<bool> (m));

	r(i, n) r(j, m) {
		l a;cin >> a;
		f[i][j] = 1 == a;
	}

	l ans = 0;

	function<void(l,l, vector<vector<bool>>, l)> dfs=[&](l y, l x, vector<vector<bool>> sp, l cnt) {
		sp[y][x] = false;
		ans = max(ans, ++cnt);

		r0(dy)r0(dx) {
			if (dy!=0 && dx !=0 ) continue;
			l ny = y + dy, nx = x + dx;

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;

			if (sp[ny][nx]) {
				dfs(ny, nx, sp, cnt);
			}
		}
	};


	r(i, n) r(j, m) {
		if (f[i][j]) dfs(i, j, f, 0);
	}

	cout << ans << endl;
}