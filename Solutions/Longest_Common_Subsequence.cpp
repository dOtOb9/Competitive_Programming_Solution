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


void demo() {
    string x,y;cin>>x>>y;

    l sx=x.size(), sy=y.size();

    vector<vector<l>> dp(sx+1, vector<l>(sy+1, 0));

    r1(i, sx+1) {
        r1(j, sy+1) {
            if (x[i-1]==y[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j]=max(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
            }
        }
    }

    cout<<dp[sx][sy]<<endl;
}

int main() {
    l n;cin>>n;

    r(i, n) demo();
}