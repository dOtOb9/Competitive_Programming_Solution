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
    int h, w;
    cin >> h >> w;

    vector<string> s(h);

    rep(i, h) {
        cin >> s[i];
    }

    int x_st = inf, y_st = inf, x_ed = 0, y_ed = 0;

    rep(y, h) {
        rep(x, w) {
            if (s[y][x] == '#') {
                x_st = min(x_st, x);
                y_st = min(y_st, y);
                x_ed = max(x_ed, x);
                y_ed = max(y_ed, y);
            }
        }
    }

    for (int y = y_st; y < y_ed + 1; ++y) {
        for (int x = x_st; x < x_ed + 1; ++x) {
            if (s[y][x] == '.') {
                cout << y + 1 << " " << x + 1 << endl;
            }
        }
    }
}