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


int main(){
    // データの入力
    int V,E,r;
    scanf("%d %d %d",&V,&E,&r);

    // グラフの配列
    vector<vector<pair<int, int>>> G(V);

    int s,t,d;

    // データの入力
    rep(i,E){
        scanf("%d %d %d",&s,&t,&d);
        G[s].push_back({t, d});
    }

    // 最短距離を格納
    vector<int> mincost(V, inf);

    // 開始位置を0に設定
    mincost[r] = 0;

    deque<int> deq;
    deq.push_back(r);

    // queueの外かどうか
    vector<bool> out_queue(V, true);
    out_queue[r] = false;

    // ダイクストラ法
    while(!deq.empty()){
        int u = deq.front(); 
        deq.pop_front(); 
        
        out_queue[u] = true;
        
        rep(i, G[u].size()){
            int v = G[u][i].first, c = G[u][i].second;
            
            if( mincost[v] > mincost[u] + c ) {
                mincost[v] = mincost[u] + c;
                
                if(out_queue[v]) {
                deq.push_back(v);
                
                out_queue[v] = false;
                }
            }
        }
    }

    // 結果の出力
    rep(i,V) {
        if( mincost[i] == inf) puts("INF");
        else printf("%d\n",mincost[i]);
    }

    return 0;
}
