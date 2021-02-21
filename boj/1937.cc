#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int mat[500][500];
int dp[500][500];
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0, -1}};

int dy(int a, int b, int n){
    if(dp[a][b] != 0) return dp[a][b];
    int cou = 0;
    for(int i = 0; i < 4; ++i){
        int nx = a + dir[i][0];
        int ny = b + dir[i][1];
        if(nx >= 0 && nx < n && ny >= 0 && ny <  n){
            if(mat[nx][ny] < mat[a][b]){
                ++cou;
            }
        }
    }
    int ans = 1;
    if(cou == 0){
        return dp[a][b] = 1;
    }
    else{
        for(int i = 0; i < 4; ++i){
            int nx = a + dir[i][0];
            int ny = b + dir[i][1];
            if(nx >= 0 && nx < n && ny >= 0 && ny <  n && mat[nx][ny] < mat[a][b]){
                ans = max(ans, dy(nx, ny, n) + 1);
                
            }
        }
    }
    return dp[a][b] = ans;
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        for(int j =0; j < n; ++j){
            scanf("%d", &mat[i][j]);
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(dp[i][j] == 0){
                dy(i, j, n);
            }
        }
    }
    int ans = 0;
    for(int i =0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(ans < dp[i][j]) ans = dp[i][j];
        }
    }
    printf("%d", ans);
}
