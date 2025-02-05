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

    vector<pll> polls;

    vector<vector<bool>> f(6000, vector<bool>(6000, false));

    r(i, n) {
        l x,y;cin>>x>>y;

        polls.push_back({x,y});

        f[y][x]=true;
    }

    l ans=0;

    function<bool(l,l)> check =[&](l x, l y) {
        if (x<0 or x>=6000 or y<0 or y>=6000) return false;

        bool flag=f[y][x];

        return flag;
    };


    r(i, n) r(j,n) {
        if (i==j) continue;

        l dx=polls[i].first-polls[j].first, dy=polls[i].second-polls[j].second;

        l x=polls[j].first, y=polls[j].second;


        if ((check(x+dy, y-dx) and check(x+dx+dy, y-dx+dy)) or (check(x-dy, y+dx) and check(x+dx-dy, y+dx+dy))) {
            ans=max(ans, dy*dy+dx*dx);
        }
    }

    cout<<ans<<endl;
}