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
    l n, m;cin>>n>>m;

    vector<vector<vector<l>>> dp(n+1, vector<vector<l>> (n, vector<l>(n, INF)));

    r(i, n) dp[0][i][i]=0;

    r(i, m) {
        l a, b;cin>>a>>b;--a;--b;

        l t;cin>>t;

        dp[0][a][b]=t;
        dp[0][b][a]=t;
    }

    r(i, n) {
        r(j, n) r(k, n) {
            if (dp[i][j][i]==INF or dp[i][i][k]==INF) dp[i+1][j][k]=dp[i][j][k];
            else dp[i+1][j][k]=min(dp[i][j][k], dp[i][j][i]+dp[i][i][k]);
        }
    }

    l ans=INF;

    r(i, n) {
        l sum=0;

        r(j, n) sum = max(sum, dp[n][i][j]);

        ans=min(ans, sum);
    }

    cout<<ans<<endl;
}