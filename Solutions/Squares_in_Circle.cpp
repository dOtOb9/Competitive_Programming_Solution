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
    l R;cin>>R;

    l y=1.5;

    l ans=0;

    r(i, R+1) {
        double ny=i+0.5;

        l le=0, ri=R;

        while(ri-le>1) {
            l mid=(ri+le)/2;

            double nx=mid+0.5;

            if ((ny*ny+nx*nx)<=R*R) le=mid;
            else ri=mid;
        }

        ans+=le;
    }

    cout<<ans*4+1<<endl;
}