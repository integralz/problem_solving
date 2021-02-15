#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> find(vector <vector <int> > &a){
    vector <int> v((int)a.size(), -1);
    v[1] = 0;
    queue <int> que;
    que.push(1);
    
    while(!que.empty()){
        int n = que.front();
        que.pop();
        for(int i = 0; i < (int)a[n].size(); ++i){
            if(v[a[n][i]] == -1){
                que.push(a[n][i]);
                v[a[n][i]] = v[n] + 1;
            }
        }
    }
    return v;
}

void dfs(int n, vector <int> &dist, vector <int> &ans, vector <vector <int> > &v, vector <bool> &used){
    if(!used[n]){
        used[n] = true;
        ans[n] = dist[n];
    }
    
    for(int i = 0; i < (int)v[n].size(); ++i){
        int a = v[n][i];
        if(!used[a] && dist[n] < dist[a]){
            dfs(a, dist, ans, v, used);
        }
        if(dist[n] < dist[a]){
            ans[n] = min(ans[a], ans[n]);
        }
        else{
            ans[n] = min(ans[n], dist[a]);
        }
    }
}

void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    
    vector <vector <int> > v(a + 1);
    
    for(int i = 0; i < b; ++i){
        int row, col;
        scanf("%d%d", &row, &col);
        v[row].push_back(col);
    }
    vector <int> dist = find(v);
    vector <bool> used(a + 1, false);
    vector <int> ans(a + 1, -1);
    dfs(1, dist, ans, v, used);
    for(int i = 1; i <= a; ++i){
        printf("%d ", ans[i]);
    }
    printf("\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}
