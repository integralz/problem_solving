#include <iostream>
#include <cstdio>
using namespace std;

int mat[100000];
int color[100001];
int want[100000];
int got[100000];

int main(void){
    int num;
    int a, b;
    int su;
    int last;
    bool ans;
    int que;
    int p;
    scanf("%d", &num);
    while(num--){
        su = 0;
        last = -1;
        scanf("%d%d", &a, &b);
        for(int i =0; i <= a; ++i){
            color[i] = 0;
        }
        for(int i =0 ; i < a; ++i){
            scanf("%d", &mat[i]);
        }
        for(int i =0; i < a; ++i){
            scanf("%d", &want[i]);
            if(want[i] != mat[i]){
                ++color[want[i]];
                ++su;
            }
        }
        for(int i = 0; i < b; ++i){
            scanf("%d", &got[i]);
        }
        for(int i = 0; i < b; ++i){
            if(color[got[i]]){
                last = i;
                --color[got[i]];
                --su;
            }
        }
        if(su == 0){
            ans = false;
            for(int i = 0; i < a; ++i){
                if(want[i] == got[b - 1]){
                    que = i;
                    ans = true;
                    break;
                }
            }
            if(ans == true){
                printf("YES\n");
                p = 0;
                for(int i = 0; i <= last; ++i){
                    for(int j = 0; j < a; ++j){
                        if(got[i] == want[j] && got[i] != mat[j]){
                            mat[j] = want[j];
                            for(int k = p; k <= i; ++k){
                                printf("%d ", j + 1);
                            }
                            p = i + 1;
                            break;
                        }
                    }
                }
                for(int i = last + 1; i < b; ++i){
                    printf("%d ", que + 1);
                }
                printf("\n");
            }
            else printf("NO\n");
        }
        else printf("NO\n");
    }
}
