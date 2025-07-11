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
#include <stack>

using namespace std;
using l = long long;
using ul = unsigned long long;

const int inf =  2147483647;         // 2e9     1 << 30
const l INF = 9223372036854775807;  // 9e18    1LL << 60

#define r(i, n) for (l i = 0; i < n; ++i)
#define r1(i, n) for (l i = 1; i < n; ++i)
#define r0(i) for (l i = -1; i < 2; ++i)
#define pll pair<l, l>

void YesNo(bool s=false) {
    if (s) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}

struct UnionFind {
    vector<l> parent, rank, size;
    l tree_count;

    UnionFind(l n) : parent(n), rank(n, 0), size(n, 1), tree_count(n) {
        for (l i = 0; i < n; i++) parent[i] = i;
    }
    
    l find(l x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);  // パス圧縮
    }
    bool unite(l x, l y) {
        l rx = find(x);
        l ry = find(y);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        size[rx] += size[ry];
        if (rank[rx] == rank[ry]) rank[rx]++;

        tree_count--;

        return true;
    }
    
    bool same(l x, l y) {
        return find(x) == find(y);
    }
    
    l getSize(l x) {
        return size[find(x)];
    }
};

int main() {
    l t;cin >> t;

    r(_, t) {
        l n;cin >> n;

        vector<l> s(n);

        r(i, n) cin >> s[i];

        if (s.back() <= s[0] * 2) {
            cout << 2 << endl;
            continue;
        }

        vector<l> ns;

        for (l x : s) {
            if (x < s[0] || s.back() < x) continue;

            ns.push_back(x);
        }

        s = ns;
        n = ns.size();
        sort(s.begin(), s.end());

        bool flag = false;

        r(i, n-1) {
            if (s[i] * 2 < s[i+1]) {
                cout << -1 << endl;

                flag = true;
                break;
            }

        }
            
        if (flag) continue;

        l last = s[0], ans = 1;
        r1(i, n) {
            if (last * 2 < s[i]) {
                last = s[i-1];

                ++ans;
            }
        }

        cout << ans+1 << endl;
    }
}