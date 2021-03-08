#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
using ll = long long;

void solve(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int que =0;
    if(a == 0 && c == 0){
        for(int i =0; i < b + 1; ++i){
            printf("%d", que);
            if(que ==0){
                que = 1;
            }
            else{
                que =0;
            }
        }
    }
    else if(a ==0){
        for(int i =0; i < c + 1; ++i){
            printf("1");
        }
        for(int i =0; i < b; ++i){
            printf("%d", que);
            if(que ==0){
                que = 1;
            }
            else{
                que =0;
            }
        }
    }
    else if(c ==0){
        for(int i =0; i < a + 1; ++i){
            printf("0");
        }
        que = 1;
        for(int i =0; i < b; ++i){
            printf("%d", que);
            if(que ==0){
                que = 1;
            }
            else{
                que =0;
            }
        }
    }
    else{
        for(int i =0; i < a + 1; ++i){
            printf("0");
        }
        for(int i =0; i < c + 1; ++i){
            printf("1");
        }
        for(int i =0; i < b - 1; ++i){
            printf("%d", que);
            if(que ==0){
                que = 1;
            }
            else{
                que =0;
            }
        }
    }
    printf("\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


