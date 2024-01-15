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
    int n;
    cin >> n;

    vector<int> a(n), b(n);

    rep(i, n) cin >> a[i] >> b[i];
    
    vector<int> ans(n);
    
    rep(i, n) ans[i] = i;

    stable_sort(ans.begin(), ans.end(), [&] (int i, int j) {
        return  (ll) a[i] * (a[j] + b[j]) > (ll) a[j] * (a[i] + b[i]);
    });

    rep(i, n) cout << ans[i] + 1 << " \n"[i == n - 1];
}