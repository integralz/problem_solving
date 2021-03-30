#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
using ll = long long;

ll mat[1001][1001];

ll dfs(int n, int k, int a){
    if(mat[a][k] != -1){
        return mat[a][k];
    }
    else{
        return mat[a][k] = (dfs(n, k, a - 1) + dfs(n, k - 1, n - a)) % (1000000007);
    }
}

void solve(){
    for(int i =0; i < 1001; ++i){
        for(int j =0; j < 1001; ++j){
            mat[i][j] = -1;
        }
    }
    for(int i =0; i < 1001; ++i){
        mat[i][1] = 1;
    }
    for(int i =0; i < 1001; ++i){
        mat[0][i] = 1;
    }
    int n, k;
    scanf("%d%d", &n, &k);
    ll ans = dfs(n, k, n);
    printf("%lld\n", ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    
    while(n--){
        solve();
    }
}



