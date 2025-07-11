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
    string s;cin >> s;
    l q;cin >> q;

    deque<char> deque;

    for (char c: s) deque.push_back(c);

    bool isRiv = false;;

    r(i, q) {
        l t;cin >> t;

        if (t == 1) isRiv = !isRiv;
        else {
            l f; char c;cin >> f >> c;

            if (f == 1) {
                if (isRiv) deque.push_back(c);
                else deque.push_front(c);
            } else {
                if (isRiv) deque.push_front(c);
                else deque.push_back(c);
            }
        }
    }

    while(!deque.empty()) {
        if (isRiv) {
            cout << deque.back();
            deque.pop_back();
        } else {
            cout << deque.front();
            deque.pop_front();
        }
    }
    cout << endl;
}