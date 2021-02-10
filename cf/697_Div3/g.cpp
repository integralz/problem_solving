#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int mat[200001];
int dp[200001];

void solve(){
    int n;
    int a;
    int ans = -1;
    scanf("%d", &n);
    for(int i = 1; i <= 200000; ++i){
        mat[i] = 0;
        dp[i] = 0;
    }
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        ++mat[a];
    }
    for(int i = 1; i <= 200000; ++i){
        dp[i] += mat[i];
        for(int j = 2 * i; j <= 200000; j += i){
            dp[j] = max(dp[i], dp[j]);
        }
    }
    for(int i =1; i <= 200000; ++i){
        if(dp[i] > ans) ans = dp[i];
    }
    
    printf("%d\n", n - ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}
