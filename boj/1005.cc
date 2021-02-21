#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    vector <int> tim(a + 1);
    for(int i =0 ; i < a; ++i){
        scanf("%d", &tim[i +1]);
    }
    vector <vector <pair <int, int> > > v(a + 1);
    vector <int> root(a + 1);
    for(int i = 0; i < b; ++i){
        int q, w;
        scanf("%d%d", &q, &w);
        root[w]++;
        v[q].push_back({w, tim[w]});
    }
    queue <pair <int, int> > que;
    vector <int> ans(a + 1, 0);
    
    for(int i =1; i <= a; ++i){
        if(root[i] == 0){
            que.push({i, tim[i]});
            ans[i] = tim[i];
        }
    }
    int tar;
    scanf("%d", &tar);
    
    while(!que.empty()){
        int st = que.front().first;
        int cou = que.front().second;
        if(st == tar){
            printf("%d\n", cou);
            return;
        }
        que.pop();
        for(int i =0; i < v[st].size(); ++i){
            int g = v[st][i].first;
            root[g]--;
            if(ans[g] < cou + tim[g]){
                ans[g] = cou + tim[g];
            }
            if(root[g] == 0){
                que.push({g, ans[g]});
            }
        }
    }
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}

