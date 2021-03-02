#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

int l[200000];
ll ans =0;

void dfs(ll a, vector <ll> &v, vector <vector <ll> > &root){

    if((int)root[a].size() == 0){
        l[a] = 1;
    }
    else{
        for(int i =0; i < (int)root[a].size(); ++i){
            dfs(root[a][i], v, root);
            v[a] += v[root[a][i]];
            l[a] += l[root[a][i]];
        }
    }
    ans = max(ans, (v[a] + l[a] - 1) / l[a]);
}

void solve(){
    int n;
    scanf("%d", &n);
    vector <ll> v(n);
    vector <vector <ll> > root(n);
    for(int i =0; i < n - 1; ++i){
        int a;
        scanf("%d", &a);
        --a;
        root[a].push_back(i + 1);
    }
    for(int i = 0; i < n; ++i){
        scanf("%lld", &v[i]);
    }
    dfs(0, v, root);
    printf("%lld", ans);
}

int main(void){
    solve();
}


