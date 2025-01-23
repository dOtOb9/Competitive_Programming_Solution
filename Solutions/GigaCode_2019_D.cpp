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
    l h, w, K, V;cin>>h>>w>>K>>V;

    vector<vector<l>> s(h+1, vector<l>(w+1));

    r(i, h)r(j,w) {
        l a;cin>>a;

        s[i+1][j+1]=s[i][j+1]+s[i+1][j]-s[i][j]+a;
    }

    l ans=0;

    r(i, h+1) r(j, w+1) {
        r(y, h+1-i) r(x, w+1-j) {
            if (s[i+y][j+x]-s[i+y][x]-s[y][j+x]+s[y][x]+i*j*K<=V) ans=max(ans, i*j);
        }
    }

    cout<<ans<<endl;
}