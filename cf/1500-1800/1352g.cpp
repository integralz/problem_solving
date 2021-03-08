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
    int n;
    scanf("%d", &n);
    if(n == 2 || n == 3){
        printf("-1\n");
    }
    else{
        if(n % 2 == 0){
            int a = n - 3;
            for(int i = 1; i < a; i += 2){
                printf("%d ", i);
            }
            printf("%d %d %d ", n - 1, n - 3, n);
            for(int i = n - 2; i >= 1; i -= 2){
                printf("%d ", i);
            }
            printf("\n");
        }
        else{
            int a = n - 3;
            for(int i = 2; i < a; i += 2){
                printf("%d ", i);
            }
            printf("%d %d %d ", n - 1, n - 3, n);
            for(int i = n - 2; i >= 1; i -= 2){
                printf("%d ", i);
            }
            printf("\n");
        }
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


