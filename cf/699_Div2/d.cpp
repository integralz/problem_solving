#include <iostream>
#include <cstdio>
using namespace std;

char mat[1000][1000];
int main(void){
    int num;
    int a, b;
    int same1, same2, same3;
    scanf("%d", &num);
    while(num--){
        scanf("%d%d", &a, &b);
        for(int i =0; i < a; ++i){
            for(int j =0 ; j < a; ++j){
                scanf("%c", &mat[i][j]);
                if(mat[i][j] == '\n')
                    scanf("%c", &mat[i][j]);
            }
        }
        same1 = -1;
        for(int i =0; i < a; ++i){
            for(int j = i + 1; j < a; ++j){
                if(mat[i][j] == mat[j][i]){
                    same1 = i;
                    same2 = j;
                    break;
                }
            }
            if(same1 != -1) break;
        }
        if(same1 != -1){
            printf("YES\n");
            for(int i =0; i < b + 1; ++i){
                if(i % 2 == 0){
                    printf("%d ", same1 + 1);
                }
                else{
                    printf("%d ", same2 + 1);
                }
            }
            
            printf("\n");
        }
        else{
            if(a == 2){
                if(b % 2 == 1){
                    printf("YES\n");
                    for(int i = 0; i < b + 1; ++i){
                        if(i % 2 == 1){
                            printf("%d ", 1);
                        }
                        else{
                            printf("%d ", 2);
                        }
                    }
                    printf("\n");
                }
                else{
                    printf("NO\n");
                }
            }
            else{
                printf("YES\n");
                if(b % 2 == 1){
                    for(int i =0; i < b + 1; ++i){
                        if(i % 2 == 1){
                            printf("%d ", 2);
                        }
                        else{
                            printf("%d ", 1);
                        }
                    }
                    printf("\n");
                }
                else{
                    for(int i = 0; i < a; ++i){
                        for(int j = 0; j < a; ++j){
                            for(int k = 0; k < a; ++k){
                                if(i != j && j != k && i != k && mat[i][j] == mat[j][k]){
                                    same1 = i;
                                    same2 = j;
                                    same3 = k;
                                    break;
                                }
                            }
                            if(same1 != -1) break;
                        }
                        if(same1 != -1) break;
                    }
                    if(b % 4 == 0){
                        for(int i = 0; i < b / 4; ++i){
                            printf("%d %d %d %d ", same2 + 1, same3 + 1, same2 + 1, same1 + 1);
                        }
                        printf("%d\n", same2 + 1);
                    }
                    else{
                        for(int i = 0; i < b / 4; ++i){
                            printf("%d %d %d %d ", same1 + 1, same2 + 1, same3 + 1, same2 + 1);
                        }
                        printf("%d %d %d\n", same1 + 1, same2 + 1, same3 + 1);
                    }
                }
            }
        }
    }
}
