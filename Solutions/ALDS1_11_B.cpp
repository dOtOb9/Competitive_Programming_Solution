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
using ll = long long;
using ull = unsigned long long;

const int inf = 1 << 30;
const ll INF = 1LL << 60;

#define rep(i, n) for (int i = 0; i < n; ++i)


int main () {
    int n;
    cin >> n;

    vector<vector<int>> v(n);

    rep(i, n) {
        int u, k;
        cin >> u >> k;

        rep(j, k) {
            int V;
            cin >> V;
            v[u - 1].push_back(--V);
        }
        sort(v[u - 1].begin(), v[u - 1].end());
    }

    vector<int> d(n), f(n); 

    int t = 0;

    vector<bool> seen(n, false);

    function<void(int)> dfs = [&](int id) {
        if (seen[id]) return;
        seen[id] = true;

        d[id] = ++t;

        int k = v[id].size();

        rep(i, k) {
            dfs(v[id][i]);
        }
        f[id] = ++t;
        return;
    };

    
    rep(i, n) {
        if (seen[i]) continue;

        dfs(i);
    }

    rep(i, n) {
        cout << i + 1 << " " << d[i] << " " << f[i] << endl;
    }
}
