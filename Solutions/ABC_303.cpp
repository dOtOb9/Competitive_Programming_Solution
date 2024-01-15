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

const int inf =  2147483647;         // 2e9     1 << 30
const ll INF = 9223372036854775807;  // 9e18    1LL << 60

#define rep(i, n) for (int i = 0; i < n; ++i)
#define pii pair<int, int>

int main () {
	int n, m, h, k;
	cin >> n >> m >> h >> k;
	string s;
	cin >> s;
	set<pair<int, int>> st;
	for (int i = 0;i < m; ++i) {
		int x, y; cin >> x >> y;
		st.insert({x, y});
	}
	int nx = 0, ny = 0;
	for (int i = 0; i < n; ++i) {
		int dx = 0, dy = 0;
		if (s[i] == 'R') dx = 1;
		if (s[i] == 'L') dx = -1;
		if (s[i] == 'U') dy = 1;
		if (s[i] == 'D') dy = -1;

		nx += dx, ny += dy;
		if (--h < 0) {
			cout << "No" << endl;
			return 0;
		}
		if (h < k && st.count({nx, ny})) {
			h = k;
			st.erase({nx, ny});
		}
	}
	cout << "Yes" << endl;
}