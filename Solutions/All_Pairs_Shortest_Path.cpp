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
    l V, E;cin>>V>>E;

    vector<vector<vector<l>>> di(V+1, vector<vector<l>> (V, vector<l> (V, INF)));

    r(i, V) r(j ,V+1)di[j][i][i]=0;

    r(i, E) {
        l s, t, d;cin>>s>>t>>d;

        di[0][s][t]=d;
    }

    r(i, V) {

        r(j, V) {
            r(k, V) {
                if (di[i][j][i]==INF or di[i][i][k]==INF) di[i+1][j][k]=di[i][j][k];
                else di[i+1][j][k]=min(di[i][j][k], di[i][j][i]+di[i][i][k]);
            }
        }
    }

    r(i, V) r(j, V){

        if (di[V][i][j] == INF or di[V][j][i]==INF) continue;

        if (di[V][i][j] + di[V][j][i] <0 ) {
            cout<< "NEGATIVE CYCLE" <<endl;
            return 0;
        }
    }

    r(i, V) {
        r(j, V) {
            if (di[V][i][j]==INF) cout<<"INF";
            else cout<<di[V][i][j];

            cout << " \n"[j == V - 1];
        }
    }
}