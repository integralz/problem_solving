#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void solve(){
    int n;
    scanf("%d", &n);
    vector <vector <int> > v(n + 1);
    vector <int> ans(n + 1, 1);
    vector <bool> root(n + 1, 0);
    for(int i =0; i < n; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue <int> que;
    for(int i = 1; i <= n; ++i){
        if((int)v[i].size() == 1){
            que.push(i);
        }
    }
    while(!que.empty()){
        int a = que.front();
        root[a] = 1;
        int b = v[a][0];
        que.pop();
        int q = -1;
        ans[b] += ans[a];
        for(int i =0; i < (int)v[b].size(); ++i){
            if(v[b][i] == a){
                q = i;
                break;
            }
        }
        v[a].clear();
        v[b].erase(v[b].begin() + q);
        if((int)v[b].size() == 1){
            que.push(b);
        }
        
    }
    vector <int> g;
    int q = 0;
    ll ans1 = 0;
    for(int i =1; i <= n; ++i){
        if(root[i] == 0){
            g.push_back(ans[i]);
            q += ans[i];
        }
    }
    ans1 += (ll)q * (q - 1);
    for(int i =0; i < g.size(); ++i){
        ans1 -= (ll)g[i] * (g[i] - 1) / 2;
    }
    printf("%lld\n", ans1);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


