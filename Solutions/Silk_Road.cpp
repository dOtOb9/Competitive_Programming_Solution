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
    l n,m;cin>>n>>m;

    vector<l> d(n), c(m);

    r(i, n) cin>>d[i];

    r(i, m) cin>>c[i];


    vector<vector<l>> dp(n+1, vector<l> (m+1, INF));

    r(i, m+1) dp[0][i]=0;

    r(i, n) {
        r(j,m) {
            dp[i][j+1]=min(dp[i][j+1], dp[i][j]);
            
            if (dp[i][j]!=INF) dp[i+1][j+1]=min(dp[i+1][j+1], dp[i][j]+d[i]*c[j]);
        }
    }

    l ans=INF;

    r(i, m+1) ans=min(ans, dp[n][i]);

    cout<<ans<<endl;
}