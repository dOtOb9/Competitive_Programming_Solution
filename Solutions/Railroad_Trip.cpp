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

    vector<l> p(m);

    r(i,m) cin>>p[i];

    vector<l> cnt(n);

    r1(i,m) {
        l x=min(p[i], p[i-1]);
        l y=max(p[i], p[i-1]);

        cnt[x-1]++;
        cnt[y-1]--;
    }

    r1(i,n) cnt[i]+=cnt[i-1];

    
    vector<l> a(n-1), b(n-1),c(n-1);

    r(i,n-1) cin>>a[i]>>b[i]>>c[i];
    
    
    l ans=0;

    r(i,n-1) ans+=min(a[i]*cnt[i], b[i]*cnt[i]+c[i]);

    cout<<ans<<endl;
}