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


int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<vector<int>> c(m);

    rep(i, n) {
        int num;
        cin >> num;
        c[--num].push_back(i);
    }

    rep(i, m) {
        string sp = s;
        rep(j, c[i].size()) {
            sp[c[i][(j + 1) % c[i].size()]] = s[c[i][j]];
        }
        s = sp;
    }

    cout << s << endl;
}