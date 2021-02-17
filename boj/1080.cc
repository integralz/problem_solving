#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int row, col;
    scanf("%d%d", &row, &col);
    vector <vector <int> > mat(row);
    vector <vector <int> >root(row);
    for(int i =0; i < row; ++i){
        for(int j =0; j < col; ++j){
            int a;
            scanf("%1d", &a);
            mat[i].push_back(a);
        }
    }
    for(int i =0; i < row; ++i){
        for(int j  =0; j < col; ++j){
            int a;
            scanf("%1d", &a);
            root[i].push_back(a);
        }
    }
    int ans = 0;
    for(int i = 0; i < row - 2; ++i){
        for(int j =0; j < col - 2; ++j){
            if(mat[i][j] != root[i][j]){
                ans++;
                for(int k =0; k < 3; ++k){
                    for(int z = 0; z < 3; ++z){
                        if(mat[i + k][j + z] == 1){
                            mat[i + k][j + z] =0;
                        }
                        else{
                            mat[i + k][j + z] = 1;
                        }
                    }
                }
            }
        }
    }
    for(int i =0; i < row; ++i){
        for(int j =0; j < col; ++j){
            if(mat[i][j] != root[i][j]){
                printf("-1");
                return 0;
            }
        }
    }
    printf("%d", ans);
}

