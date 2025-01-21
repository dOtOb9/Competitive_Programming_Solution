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
    l n, x;cin>>n>>x;
    
    if (n==0 and x==0) exit(0);

    l ans=0;

    r1(i, n+1)for(l j=i+1;j<n+1;++j) for(l k=j+1;k<n+1;++k) {
        if (i+j+k==x) ++ans;
    }

    cout<<ans<<endl;
}

int main() {
    while(true) test();
}