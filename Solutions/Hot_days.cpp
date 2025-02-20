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
using l = long long;
using ul = unsigned long long;

const int inf =  2147483647;         // 2e9     1 << 30
const l INF = 9223372036854775807;  // 9e18    1LL << 60

#define r(i, n) for (l i = 0; i < n; ++i)
#define r1(i, n) for (l i = 1; i < n; ++i)
#define r0(i) for (l i = -1; i < 2; ++i)
#define pll pair<l, l>


int main() {
    l d, n;cin>>d>>n;

    vector<l> t(d);

    r(i, d) cin>>t[i];

    vector<l> a(n),b(n),c(n);

    r(i, n) cin>>a[i]>>b[i]>>c[i];

    vector<vector<l>> dp(d+1, vector<l>(n));

    r1(i, d) {
        r(j, n) {
            if (a[j] <= t[i-1] and t[i-1] <= b[j]) {
                r(k, n) {
                    if (a[k] <= t[i] and t[i] <= b[k]) {
                        dp[i+1][k]=max(dp[i+1][k], dp[i][j] + abs(c[k]-c[j]));
                    }
                }
            }
        }
    }

    l ans=0;

    r(i, n) ans=max(ans, dp[d][i]);
    cout<<ans<<endl;
}