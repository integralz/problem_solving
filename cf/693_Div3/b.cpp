#include <iostream>
#include <cstdio>
using namespace std;

void solve(){
    int n; int a;
    int sum = 0;
    bool t = false;
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        sum += a;
        if(a == 1) t = true;
    }
    if(t){
        if(sum % 2 == 0) printf("YES\n");
        else printf("NO\n");
    }
    else{
        if(sum % 4 == 0) printf("YES\n");
        else printf("NO\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}
