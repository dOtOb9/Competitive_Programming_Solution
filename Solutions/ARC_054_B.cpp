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
    double p;cin>>p;

    function<double(double)> f=[&](double x) {
        return x + p/pow(2, x/1.5);
    };

    double le=0, ri=INF;

    while (ri-le>0.0000001) {
        double c1 = (ri+le*2)/3;
        double c2 = (ri*2+le)/3;

        if (f(c1)<f(c2)) ri=c2;
        else le=c1;
    }

    printf("%.10f\n", f(le));
}