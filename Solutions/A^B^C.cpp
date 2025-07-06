#include <iostream>
#include <vector>
#include <set>
using namespace std;
using l = long long;

l mod_pow(l base, l exp, l mod) {
    l result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    l a, b, c; cin >> a >> b >> c;

    a %= 10;

    // aの累乗の周期（mod 10）
    vector<l> cycle;
    set<l> seen;
    l res = 1;
    while (true) {
        res = res * a % 10;
        if (seen.count(res)) break;
        cycle.push_back(res);
        seen.insert(res);
    }

    l cycle_len = cycle.size();

    // b^c mod cycle_len を求める
    l exp = mod_pow(b, c, cycle_len);
    if (exp == 0) exp = cycle_len;

    // 答え出力（1-indexed）
    cout << cycle[exp - 1] << endl;
}
