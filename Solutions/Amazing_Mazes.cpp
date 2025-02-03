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


void test() {
    l w, h;cin>>w>>h;

    if (w==0 && h==0) exit(0);

    vector<vector<bool>> wall_right(h, vector<bool>(w,true)), wall_under(h, vector<bool>(w, true));


    r(i, h) {
        r(j, w-1) {
            l a;cin>>a;

            wall_right[i][j]=1==a;
        }

        if (i==h-1) break;

        r(j, w) {
            l a;cin>>a;

            wall_under[i][j]=1==a;
        }
    }


    vector<vector<l>> d(h, vector<l> (w, 0));

    d[0][0]=1;

    queue<pll> q;q.push({0,0});

    while(!q.empty()) {
        auto u=q.front();q.pop();

        l y=u.first, x=u.second;

        if (!wall_under[y][x]) if (d[y+1][x]==0) {
            d[y+1][x]=d[y][x]+1;

            q.push({y+1, x});
        }

        if (!wall_right[y][x]) if (d[y][x+1]==0) {
            d[y][x+1]=d[y][x]+1;

            q.push({y, x+1});
        }

        if (y!=0) if (!wall_under[y-1][x] && d[y-1][x]==0) {
            d[y-1][x]=d[y][x]+1;

            q.push({y-1, x});
        }

        if (x!=0) if (!wall_right[y][x-1] && d[y][x-1]==0) {
            d[y][x-1]=d[y][x]+1;

            q.push({y, x-1});
        }
    }

    cout<<d[h-1][w-1]<<endl;
}


int main() {
    while(true) test();
}