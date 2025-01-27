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
#define r0(i) for (l i = -1; i<=1; ++i)
#define pll pair<l, l>

int main() {
    l n,K;cin>>n>>K;

    vector<l> ab(n, -1);

    r(i,K) {
        l a,b;cin>>a>>b;

        ab[--a]=--b;
    }

    vector<vector<vector<l>>> dp(3, vector<vector<l>> (n,{0,0}));


    dp[0][0][0]=1;
    dp[1][0][0]=1;
    dp[2][0][0]=1;

    if (ab[0]!=-1) {
        dp[(ab[0]+1)%3][0][0]=0;
        dp[(ab[0]+2)%3][0][0]=0;
    }


    r1(j,n) {
        r(i,3) {
            dp[i][j][0]=dp[(i+1)%3][j-1][0]+dp[(i+2)%3][j-1][0]+dp[(i+1)%3][j-1][1]+dp[(i+2)%3][j-1][1];

            dp[i][j][1]=dp[i][j-1][0];

            if (ab[j]==-1) continue;

            dp[(ab[j]+1)%3][j]={0,0};
            dp[(ab[j]+2)%3][j]={0,0};

            dp[i][j][0]%=10000;
            dp[i][j][1]%=10000;
        }
    }

    l ans=0;

    r(i,3) {
        ans+=dp[i][n-1][0]+dp[i][n-1][1];
    }

    cout<<ans%10000<<endl;
}
