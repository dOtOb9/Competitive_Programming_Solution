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

void nans(l ans) {
    if (ans==INF) cout<<-1<<endl;
    else cout<<ans<<endl;
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
    bool unite(pll xy) {
        l rx = find(xy.first);
        l ry = find(xy.second);
        if (rx == ry) return false;
        if (rank[rx] < rank[ry]) swap(rx, ry);
        parent[ry] = rx;
        size[rx] += size[ry];
        if (rank[rx] == rank[ry]) rank[rx]++;

        tree_count--;

        return true;
    }
    
    bool same(pll xy) {
        return find(xy.first) == find(xy.second);
    }
    
    l getSize(l x) {
        return size[find(x)];
    }
};


int main() {
    l n;cin>>n;

    vector<l> h(n), s(n);

    r(i, n) cin>>h[i]>>s[i];


    l le=0, ri=INF;

    while(ri-le>1) {
        l mid = (le+ri)/2;

        vector<l> t(n);

        bool flag=false;

        r(i, n) {
            t[i] = (mid-h[i])/s[i];

            if (mid-h[i] < 0) flag=true;
        }


        sort(t.begin(), t.end());

        r(i, n) if (t[i] < i) flag=true;

        if (flag) le=mid;
        else ri=mid;
    }

    cout<<ri<<endl;
}