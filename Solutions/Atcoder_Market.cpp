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

    vector<l> a(n), b(n), ab;

    r(i,n) {
        l A, B;cin>>A>>B;

        a[i]=A;
        b[i]=B;

        ab.push_back(A);
        ab.push_back(B);
    }


    l ans=INF;

    for (auto st : ab) for (auto ed : ab) {

        l sum=0;

        r(i, n) {
            sum += abs(st-a[i]) + abs(a[i]-b[i]) + abs(b[i]-ed);
        }

        ans=min(ans, sum);
    }

    cout<<ans<<endl;
}