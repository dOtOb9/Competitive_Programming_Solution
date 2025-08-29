#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;
using namespace atcoder;
using mint = modint998244353;
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
    l Q;cin >> Q;

    queue<l> q;
    q.push(1);
    mint ans = 1;

    r(_, Q) {
        l t;cin >> t;

        if (t == 1) {
            l x;cin >> x;
            q.push(x);

            ans = ans * 10 + x;
        }
        if (t == 2) {
            l x = q.front();q.pop();
            ans -= x * mint(10).pow(q.size());
        }
        if (t == 3) {
            cout << ans.val() << endl;
        }
    }
}