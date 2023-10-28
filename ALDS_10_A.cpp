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

const int inf = 1 << 30;
const ll INF = 1LL << 60;

#define rep(i, n) for (int i = 0; i < n; ++i)

int main () {
    int n;
    cin >> n;

    vector<int> dp(n + 1, inf);


    function<void(int)> fib = [&](int i) {
        if (i > n) return;

        dp[i] = dp[i - 1] + dp[i  - 2];

        fib(i + 1);
    };

    dp[0] = 1;
    dp[1] = 1;

    fib(2);

    cout << dp[n] << endl; 
}
