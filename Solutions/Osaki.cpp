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


void test() {
    l n;cin>>n;

    if (n==0) exit(0);

    vector<l> d(24*60*60);

    r(i, n) {

        l hs, ms, ss, he, me, se;

        scanf("%lld:%lld:%lld",&hs,&ms,&ss);
        scanf("%lld:%lld:%lld",&he,&me,&se);

        d[hs*3600+ms*60+ss]++;
        d[he*3600+me*60+se]--;

    }

    r1(i, 24*60*60) d[i]+=d[i-1];

    l ans=0;

    r(i, 24*60*60) ans=max(ans, d[i]);

    cout<<ans<<endl;
}

int main() {
    while(true) test();
}