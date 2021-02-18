#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define long long ll;

void solve(){
    int n;
    scanf("%d", &n);
    int que = 1;
    if(n % 2 == 0){
        for(int i =0; i < n; ++i){
            if(i % 2 == 0){
                printf("%d ", que + 1);
            }
            else{
                printf("%d ", que);
                que += 2;
            }
        }
    }
    else{
        for(int i =0; i < n - 3; ++i){
            if(i % 2 == 0){
                printf("%d ", que + 1);
            }
            else{
                printf("%d ", que);
                que += 2;
            }
        }
        printf("%d %d %d", que + 2, que, que + 1);
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


