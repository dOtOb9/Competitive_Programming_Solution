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
    l n;cin>>n;

    vector<l> a(n);

    r(i, n) cin>>a[i];

    vector<vector<l>> dp(n-1, vector<l> (21));

    dp[0][a[0]]=1;

    r1(i, n-1) {
        r(j, 21) {
            if (j-a[i]>=0) dp[i][j]+=dp[i-1][j-a[i]];
            if (j+a[i]<21) dp[i][j]+=dp[i-1][j+a[i]];
        }
    }

    cout<<dp[n-2][a[n-1]]<<endl;
}