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
    int n;
    cin >> n;
    vector<int> ans;

    cout << n << ": ";

    int list = pow(n, 0.5) + 1;

    for (int i = 2; i < list; ++i) {
        while (n % i == 0) {
            n /= i;
            ans.push_back(i);
        }
    }
    if (n != 1) ans.push_back(n);

    rep(i, ans.size()) cout << ans[i] << " \n"[i == ans.size() - 1];
}
