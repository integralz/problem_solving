#include <iostream>
#include <cstdio>
using namespace std;

void solve(){
    int a,b,n;
    int cou = 0;
    int ans = 1;
    
    scanf("%d%d%d", &a, &b, &n);
    while(1){
        if(a % 2 == 0){
            a /= 2;
            ++cou;
        }
        else break;
    }
    while(1){
        if(b % 2 == 0){
            b /= 2;
            ++cou;
        }
        else break;
    }
    
    for(int i = 0; i < cou; ++i){
        ans *= 2;
    }
    if(ans >= n) printf("YES\n");
    else printf("NO\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}
