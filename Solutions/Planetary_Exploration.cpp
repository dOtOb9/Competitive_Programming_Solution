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
    l m,n;cin>>m>>n;

    l K;cin>>K;

    vector<string> f(m);

    r(i,m) cin>>f[i];

    vector<vector<vector<l>>> s(3, vector<vector<l>> (m+1, vector<l>(n+1,0)));

    r(i, m)r(j,n) {
        r(k,3) s[k][i+1][j+1]=s[k][i+1][j]+s[k][i][j+1]-s[k][i][j];

        l flag=0;

        if (f[i][j]=='O') flag=1;
        if (f[i][j]=='I') flag=2;

        s[flag][i+1][j+1]++;
    }

    r(i,K) {
        l a,b,c,d;cin>>a>>b>>c>>d;

        r(j,3) {
            cout<<s[j][c][d]-s[j][c][b-1]-s[j][a-1][d]+s[j][a-1][b-1];

            if (j==2) cout<<endl;
            else cout<<" ";
        }

    }
}