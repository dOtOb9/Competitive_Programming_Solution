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
    vector<string> a(h), b(h);
    rep(i, h) cin >> a[i];
    rep(i, h) cin >> b[i];

    rep(s, h) rep(t, w) {
        bool ok = true;
        rep(i, h) rep(j, w) {
            if (a[(i - s + h) % h][(j - t + w) % w] != b[i][j]) ok = false;
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}