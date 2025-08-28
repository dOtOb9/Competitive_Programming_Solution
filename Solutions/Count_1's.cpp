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

const int inf = 2147483647;        // 2e9     1 << 30
const l INF = 9223372036854775807; // 9e18    1LL << 60

#define r(i, n) for (l i = 0; i < n; ++i)
#define r1(i, n) for (l i = 1; i < n; ++i)
#define r0(i) for (l i = -1; i < 2; ++i)
#define pll pair<l, l>

void YesNo(bool s = false)
{
    if (s)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

struct UnionFind
{
    vector<l> parent, rank, size;
    l tree_count;

    UnionFind(l n) : parent(n), rank(n, 0), size(n, 1), tree_count(n)
    {
        for (l i = 0; i < n; i++)
            parent[i] = i;
    }

    l find(l x)
    {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // パス圧縮
    }
    bool unite(pll xy)
    {
        l rx = find(xy.first);
        l ry = find(xy.second);
        if (rx == ry)
            return false;
        if (rank[rx] < rank[ry])
            swap(rx, ry);
        parent[ry] = rx;
        size[rx] += size[ry];
        if (rank[rx] == rank[ry])
            rank[rx]++;

        tree_count--;

        return true;
    }

    bool same(pll xy)
    {
        return find(xy.first) == find(xy.second);
    }

    l getSize(l x)
    {
        return size[find(x)];
    }
};

//Era(n)を呼んだ後、isprime[i]=iが素数かどうか　となっている。
vector < bool > isprime;
//返り値は素数のリスト。
vector < l > Era(int n) {
	isprime.resize(n, true);
	vector < l > res;
	isprime[0] = false;
	isprime[1] = false;
	for(l i = 2; i < n; ++i) isprime[i] = true;
	for(l i = 2; i < n; ++i) {
		if(isprime[i]) {
			res.push_back(i);
			for(l j = i * 2; j < n; j += i) isprime[j] = false;
		}
	}
	return res;
}

//==================================================================================

int main() {
    l n;cin >> n;
    vector<l> s(n+1);
    r(i, n) {
        l a;cin >> a;
        if (a) s[i+1]--;
        else s[i+1]++;
    }

    r(i, n) s[i+1] += s[i];

    l m = 0, M = 0;
    l xmax = 0, xmin = 0;

    r(i, n+1) {
        xmax = max(s[i] - m, xmax);
        xmin = min(s[i] - M, xmin);

        M = max(s[i], M);
        m = min(s[i], m);
    }

    cout << xmax - xmin+1 << endl;
}