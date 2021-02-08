#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int mat[100];
int mat1[100];
int got[100][50];
vector <int> v;

int main(void){
    int num;
    int cou;
    int a;
    int ans = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; ++i){
        scanf("%d", &mat[i]);
    }
    for(int i = 0; i < num; ++i){
        mat[i + num] = mat[i];
    }
    for(int i = 0; i < 2*num; ++i){
        if(mat[2*num - i - 1] == 1) mat1[i] = 3;
        else if(mat[2*num - i - 1] == 2) mat1[i] = 4;
        else if(mat[2*num - i - 1] == 3) mat1[i] = 1;
        else if(mat[2*num - i - 1] == 4) mat1[i] = 2;
    }
    scanf("%d", &cou);
    for(int i = 0; i < cou; ++i){
        for(int j = 0; j < num; ++j){
            scanf("%d", &got[i][j]);
        }
        for(int j = 0; j < num; ++j){
            a = 0;
            for(int k = 0; k < num; ++k){
                if(mat[j + k] == got[i][k]) ++a;
                else break;
            }
            if(a == num){
                ++ans;
                v.push_back(i);
            }
            else{
                a = 0;
                for(int k = 0; k < num; ++k){
                    if(mat1[j + k] == got[i][k]) ++a;
                    else break;
                }
                if(a == num){
                    ++ans;
                    v.push_back(i);
                }
            }
            
        }
    }
    printf("%d\n", ans);
    for(int i =0; i < ans ; ++i){
        for(int j = 0; j < num; ++j){
            printf("%d ", got[v[i]][j]);
        }
        printf("\n");
    }
    
}
