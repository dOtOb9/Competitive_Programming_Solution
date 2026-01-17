#include <bits/stdc++.h>
//#include <atcoder/all>

using namespace std;
//using namespace atcoder;
//using mint = modint998244353;
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


void demo() {
	l h, w;cin >> w >> h;

	if (w == 0 && h == 0) exit(0);

	vector<vector<bool>> under_wall(h, vector<bool>(w, true));
	vector<vector<bool>> ceiling_wall(h, vector<bool>(w, true));
	vector<vector<bool>> right_wall(h, vector<bool>(w, true));
	vector<vector<bool>> left_wall(h, vector<bool>(w, true));

	r(i, h) {

		r(j, w-1) {
			l a;cin >> a;

			if (a == 0) {
				right_wall[i][j] = false;
				left_wall[i][j+1] = false;
			}
		}

		if (i == h-1) break;

		r(j, w) {
			l a;cin >> a;

			if (a == 0) {
				under_wall[i][j] = false;
				ceiling_wall[i+1][j] = false;
			}
		}
	}

	queue<pll> q;q.push({0, 0});

	vector<vector<l>> d(h, vector<l>(w, INF));

	d[0][0] = 1;

	while(!q.empty()) {
		auto [y, x] = q.front();q.pop();

		if (!right_wall[y][x]) {
			if (d[y][x+1] == INF) {
				d[y][x+1] = d[y][x] + 1;

				q.push({y, x+1});
			}
		}

		if (!left_wall[y][x]) {
			if (d[y][x-1] == INF) {
				d[y][x-1] = d[y][x] + 1;

				q.push({y, x-1});
			}
		}

		if (!ceiling_wall[y][x]) {
			if (d[y-1][x] == INF) {
				d[y-1][x] = d[y][x] + 1;

				q.push({y-1, x});
			}
		}

		if (!under_wall[y][x]) {
			if (d[y+1][x] == INF) {
				d[y+1][x] = d[y][x] + 1;

				q.push({y+1, x});
			}
		}
	}

	if (d[h-1][w-1] == INF) cout << 0 << endl;
	else cout << d[h-1][w-1] << endl;
}

int main() {
	while(true) demo();
}