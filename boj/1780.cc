#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int mat[2187][2187];
int ans[3];

void che(int row, int col, int n){
    int que = mat[row][col];
    bool gg = true;
    for(int i = row; i < row + n; ++i){
        for(int j = col; j < col +n; ++j){
            if(que != mat[i][j]){
                gg = false;
                break;
            }
        }
        if(gg == false) break;
    }
    if(gg == true){
        ans[que + 1]++;
    }
    else{
        for(int i = 0; i < 3; ++i){
            for(int j = 0; j < 3; ++j){
                che(row + i * (n/3), col + j*(n/3), n/3);
            }
        }
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    for(int i =0; i < n; ++i){
        for(int j =0 ; j < n; ++j){
            scanf("%d", &mat[i][j]);
        }
    }
    che(0,0,n);
    for(int i =0; i < 3; ++i){
        printf("%d\n", ans[i]);
    }
}

int main(void){
    solve();
}
