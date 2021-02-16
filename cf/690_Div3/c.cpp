#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

void solve(){
    int n;
    int que = -1;
    scanf("%d", &n);
    for(int i = 9; i >= 1; --i){
        if(i >= n){
            printf("%d", n);
            que = i;
            break;
        }
        else{
            n -= i;
        }
    }
    if(que == -1){
        printf("-1\n");
        return;
    }
    for(int i = que + 1; i <= 9; ++i){
        printf("%d", i);
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


