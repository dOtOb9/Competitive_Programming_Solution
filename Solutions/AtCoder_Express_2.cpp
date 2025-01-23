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
    l n,m, Q;cin>>n>>m>>Q;

    vector<vector<l>> LR(n+1, vector<l>(n+1));

    r(i, m) {
        l L, R;cin>>L>>R;

        LR[L][R]++;
    }

    r(i,n)r(j,n) {
        LR[i+1][j+1]+=LR[i][j+1]+LR[i+1][j]-LR[i][j];
    }

    r(_, Q) {
        l p, q;cin>>p>>q;--p;

        cout<<LR[q][q]-LR[p][q]-LR[q][p]+LR[p][p]<<endl;
    }
}