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

    vector<l> s(n+1, 0);

    r(i, n) {
        l a;cin>>a;

        s[i+1]=s[i]+a;
    }

    l ans=0;

    r1(k, n+1) {
        r(i,n+1-k) {
            ans=max(ans, s[i+k]-s[i]);
        }

        cout<<ans<<endl;
    }
}