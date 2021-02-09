#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int mat[100000];
int want[100000];
vector <int> v[100001];
int ans[100000];
int got[100000];


int main(void){
    int num;
    int a,b ;
    int col;
    bool t;
    scanf("%d", &num);
    while(num--){
        scanf("%d%d", &a , &b);
        
        for(int i = 0; i < a; ++i){
            scanf("%d", &mat[i]);
        }
        for(int i = 0; i < a; ++i){
            scanf("%d", &want[i]);
            if(want[i] != mat[i]){
                v[want[i]].push_back(i);
            }
        }
        for(int i = 0; i < b; ++i){
            scanf("%d", &got[i]);
        }
        col = -1;
        if((int)v[got[b - 1]].size() > 0){
            col = v[got[b - 1]].back();
            v[got[b - 1]].pop_back();
        }
        else{
            for(int i = 0; i < a; ++i){
                if(want[i] == got[b - 1]){
                    col = i;
                    break;
                }
            }
        }
        if(col == -1){
            printf("NO\n");
        }
        else{
            ans[b - 1] = col;
            for(int i =0; i < b - 1; ++i){
                if(v[got[i]].size() > 0){
                    ans[i] = v[got[i]].back();
                    v[got[i]].pop_back();
                }
                else{
                    ans[i] = col;
                }
            }
            t = false;
            for(int i = 1; i <= a; ++i){
                if(v[i].size() != 0){
                    t = true;
                }
            }
            if(t) printf("NO\n");
            else{
                printf("YES\n");
                for(int i = 0; i < b; ++i){
                    printf("%d ", ans[i] + 1);
                }
                printf("\n");
            }
        }
        for(int i = 0; i <= a; ++i){
            v[i].clear();
        }
    }
    
}
