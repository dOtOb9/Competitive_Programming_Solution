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
    l K;cin >> K;
    string s,t;cin >> s >> t;

    vector<l> cards(10, K);

    vector<vector<l>> score(2, vector<l>(10));

    r(i, 4) {
        cards[s[i] - '0']--;
        cards[t[i] - '0']--;

        score[0][s[i] - '0']++;
        score[1][t[i] - '0']++;
    }

    double win = 0;

    r1(i, 10) r1(j, 10) {
        l tk = 0, ao = 0;

        auto sp = score;

        sp[0][i]++;
        sp[1][j]++;

        r1(k, 10) {
            tk += pow(10, sp[0][k]) * k;
            ao += pow(10, sp[1][k]) * k;
        }

        if (tk > ao) {
            if(i == j && cards[j] > 0) win += cards[i] * (cards[j] - 1);
            else win += cards[i] * cards[j];
        }
    }

    printf("%.10f\n", win / (K*9-8) / (K*9-9));
}