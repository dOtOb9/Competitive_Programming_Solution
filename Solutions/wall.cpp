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
    l h, w;cin>>h>>w;

    vector<vector<vector<l>>> dp(11, vector<vector<l>>(10, vector<l>(10,INF)));

    r(i,10) dp[0][i][i]=0;

    r(i, 10)r(j,10) {
        l c;cin>>c;
        dp[0][i][j]=c;
    }

    r(i,10) r(j,10)r(k,10) {
        if (dp[i][j][i]==INF or dp[i][i][k]==INF) dp[i+1][j][k]=dp[i][j][k];
        else dp[i+1][j][k]=min(dp[i][j][k], dp[i][j][i]+dp[i][i][k]);
    }

    l ans=0;

    r(i, h)r(j, w) {
        l a;cin>>a;

        if (a==-1) continue;

        ans+=dp[10][a][1];
    }

    cout<<ans<<endl;
}