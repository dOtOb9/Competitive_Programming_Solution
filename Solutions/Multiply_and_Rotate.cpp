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
#include <numeric>

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
    l a;
    string n;
    cin >> a >> n;

    l target = stoi(n);
    l MAX = 1000000;  // N can be up to 10^6

    vector<l> d(MAX, -1);

    d[1] = 0;

    queue<l> q;q.push(1);

    while(!q.empty()) {
        auto u = q.front();q.pop();

        l x = u * a;

        if (x < MAX && d[x] == -1) {
            d[x] = d[u] + 1;
            q.push(x);
        }

        if (u >= 10 && u % 10 != 0) {
            string st = to_string(u);
            rotate(st.begin(), st.end()-1, st.end());

            l v = stoi(st);
    
            if (v < MAX && d[v] == -1) {
                d[v] = d[u] + 1;
                q.push(v); 
            }
        }
    }

    cout << d[target] << endl;
}