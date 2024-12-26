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


int main () {
    l n, W;cin>>n>>W;

    vector<l> v(n), w(n);

    r(i,n) cin>>v[i]>>w[i];

    vector<vector<l>> dp(n, vector<l>(W+1, 0));

    r(i,W+1) {
        if (i>=w[0]) dp[0][i]=v[0];
    }

    r1(i, n) {
        r(j,W+1) {
            dp[i][j]=dp[i-1][j];


            if (j-w[i]>=0) {
                dp[i][j]=max(dp[i][j], dp[i-1][j-w[i]]+v[i]);
            }
        }
    }

    cout<<dp[n-1][W]<<endl;
}