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


bool prime_number(l X) {
    if (X<2) return false;

    if (X==2) return true;

    l cnt=0;

    l x=X;

    r(i, pow(x, 0.5)+1) {
        if (i<2 or x%i!=0) continue;

        while(x%i==0) {
        x/=i;

        cnt++;
        }
    }

    return cnt==0;
}

int main() {
    vector<l> prime(101010);

    r1(i, 101010) {
        if (prime_number(i) and prime_number((i+1)/2)) {
            prime[i]++;
        }

        prime[i]+=prime[i-1];
    };


    l Q;cin>>Q;


    r(i, Q) {
        l ans=0;

        l L, R;cin>>L>>R;

        cout<<prime[R]-prime[L-1]<<endl;
    }

}