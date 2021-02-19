#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void solve(){
    int n;
    scanf("%d", &n);
    int que = n % 10;
    int ans = 0;
    int a = 1;
    while(n){
        ans += a;
        a++;
        n /= 10;
    }
    printf("%d\n", 10*que - 10 + ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


