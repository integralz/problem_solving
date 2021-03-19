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
    int n, q, q2;
    scanf("%d%d%d", &n, &q, &q2);
    int w, b;
    scanf("%d%d", &w, &b);
    int a = w + b;
    a *= 2;
    if(a > 2*n){
        printf("NO\n");
    }
    else{
        a = abs(q - q2);
        int g = min(q, q2);
        int c = max(q, q2);
        if(a / 2 + g >= w){
            if(a / 2  + n - c >= b){
                printf("YES\n");
            }
            else {
                printf("NO\n");
            }
        }
        else{
            printf("NO\n");
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



