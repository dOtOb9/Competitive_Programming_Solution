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
    l K;cin>>K;

    vector<string> f(8, "........");
    
    r(i, K) {
        l r, c;cin>>r>>c;

        f[r][c]='Q';
    }

    function<void(l,l,l,vector<string>)> dfs=[&](l y, l x, l cnt, vector<string> sp) {
        sp[y][x]='Q';
        
        if (++cnt==8) {
            r(i, 8) cout<<sp[i]<<endl;
            exit(0);
        }

        r(i, 8) r(j, 8) {

            bool flag=false;

            r0(dy)r0(dx) {
                r(k, 8) {
                    l ny=i+dy*k, nx=j+dx*k;

                    if (ny<0 or ny>=8 or nx<0 or nx>=8) continue;

                    if (sp[ny][nx]=='Q') flag=true;
                }
            }

            if (flag) continue;

            dfs(i, j, cnt, sp);
        }
    };

    if (K==8) {
        r(i,8) cout<<f[i]<<endl;
        return 0;
    }

    r(i, 8)r(j, 8) {
        bool flag=false;

        r0(dy)r0(dx) {
            r(k,8) {
                l ny=i+k*dy, nx=j+k*dx;

                if (ny<0 or ny>=8 or nx<0 or nx>=8) continue;

                if (f[ny][nx]=='Q') flag=true;
            }
        } 

        if (flag) continue;

        dfs(i, j, K, f);
    }
}