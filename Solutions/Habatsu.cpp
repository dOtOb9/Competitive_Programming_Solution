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
    l n,m;cin>>n>>m;

    vector<vector<bool>> relation(n, vector<bool>(n, false));

    r(i, m) {
        l x,y;cin>>x>>y;--x;--y;

        relation[x][y]=true;
        relation[y][x]=true;
    }


    l ans=0;

    r(i, 1<<n) {
        vector<l> party;
        r(j, n) {


            if (i & 1<<j) {
                party.push_back(j);
            }

        }
        bool flag=true;


        for (auto p : party) {
            for (auto c : party) {
                if (p==c) continue; 
                if (!relation[p][c]) flag=false;
            }
        }
        if (flag) {
            l ps=party.size();
            ans=max(ans, ps);
        }
    }

    cout<<ans<<endl;
}