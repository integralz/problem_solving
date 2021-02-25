#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

void solve(){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int ans = 0;
    ans += a;
    ans += b;
    ans += c;
    if(ans % 9 == 0){
        int g = ans / 9;
        if(a >= g && b >= g && c >= g){
            printf("YES\n");
        }
        else printf("NO\n");
    }
    else{
        printf("NO\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


