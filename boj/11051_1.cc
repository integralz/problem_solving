#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int mat[1001][1001];

int dfs(int n, int k){
    if(mat[n][k] != 0) return mat[n][k];
    if(n == k) return mat[n][k] = 1;
    return mat[n][k] = (dfs(n - 1, k) + dfs(n - 1, k - 1)) % 10007;
}

int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i =0 ; i < n + 1; ++i){
                  mat[i][0] = 1;
                  }
    printf("%d", dfs(n, k));
    
}
