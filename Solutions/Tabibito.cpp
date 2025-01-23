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

    vector<l> s(n, 0);

    r(i,n-1) {
        l a;cin>>a;

        s[i+1]=a+s[i];
    }

    l ans=0;

    l pre=0;

    r(i, m) {
        l a;cin>>a;

        ans+=abs(s[pre+a]-s[pre]);

        pre+=a;
    }

    cout<<ans%100000<<endl;
}