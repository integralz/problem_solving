#include <iostream>
#include <cstdio>
using namespace std;

int mat[100];

int main(void){
    int num;
    int a, b;
    bool c;
    int que;
    scanf("%d", &num);
    while(num--){
        c = false;
        scanf("%d%d", &a, &b);
        for(int i = 0; i < a; ++i){
            scanf("%d", &mat[i]);
        }
        for(int i = 0; i < b; ++i){
            for(int j = 0; j < a; ++j){
                if(j == a - 1){
                    c = true;
                    printf("-1\n");
                }
                else if(mat[j] < mat[j + 1]){
                    ++mat[j];
                    que = j;
                    break;
                }
            }
            if(c) break;
        }
        if(!c) printf("%d\n", que + 1);
    }
}
