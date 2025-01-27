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

    vector<l> ab(10101010);

    r(i, n) {
        l a,b;cin>>a>>b;

        ab[a]++;ab[++b]--;
    }

    r1(i, 10101010) {
        ab[i]+=ab[i-1];
    }

    l ans=0;

    r(i, 10101010) {
        ans=max(ans, ab[i]);
    }

    cout<<ans<<endl;
}