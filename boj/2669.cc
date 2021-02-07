#include <iostream>
#include <cstdio>
using namespace std;

int mat[100][100];

int main(void){
    int ans = 0;
    int arow, acol, brow, bcol;
    
    for(int i = 0; i < 100; ++i){
        for(int j =0 ; j < 100; ++j){
            mat[i][j] = 0;
        }
    }
    
    for(int i = 0; i < 4; ++i){
        scanf("%d%d%d%d", &arow, &acol, &brow, &bcol);
        for(int j = arow; j < brow; ++j){
            for(int k = acol; k < bcol; ++k){
                mat[j][k] = 1;
            }
        }
    }
    for(int i = 0; i < 100; ++i){
        for(int j = 0; j < 100; ++j){
            if(mat[i][j] == 1) ++ans;
        }
    }
    printf("%d", ans);
}
