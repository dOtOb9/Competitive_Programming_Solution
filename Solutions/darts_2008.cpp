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
    l n, m;cin>>n>>m;

    vector<l> p(n);

    r(i, n) cin>>p[i];

    p.push_back(0);

    vector<l> score;

    r(i, n+1)r(j, n+1) {
        score.push_back(p[i]+p[j]);
    }

    l ans=0;

    sort(score.begin(),score.end());

    r(i, score.size()) {
        auto it=lower_bound(score.begin(),score.end(), m-score[i]);

        l res=*it+score[i];

        if (res<=m) {
            ans=max(ans, res);
        } else {
            if (score.begin()!=it) {
                ans=max(ans,*(it-1)+score[i]);
            }
        }
    }

    cout<<ans<<endl;
}