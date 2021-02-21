#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int mat[3][100001];

int main(void){
    int n;
    scanf("%d", &n);
    mat[0][1] = 1;
    mat[1][1] = 1;
    mat[2][1] = 1;
    for(int i = 2; i <= n; ++i){
        for(int j = 0; j < 3; ++j){
            if(j == 0){
                mat[j][i] = mat[0][i - 1] + mat[2][i - 1] + mat[1][i - 1];
                mat[j][i] %= 9901;
            }
            else if(j == 1){
                mat[j][i] = mat[0][i - 1] + mat[2][i - 1];
                mat[j][i] %= 9901;
            }
            else{
                mat[j][i] = mat[0][i - 1] + mat[1][i - 1];
                mat[j][i] %= 9901;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < 3; ++i){
        ans += mat[i][n];
    }

    printf("%d", ans % 9901);
}
