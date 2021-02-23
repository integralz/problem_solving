#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 987654321;
    
    for(int i =0; i < 32; ++i){
        int c = a;
        int d = b;
        int que = 0;
        for(int j = 0; j < i; ++j){
            ++d;
            ++que;
        }
        if(d == 1) continue;
        while(c!= 0){
            c /= d;
            ++que;
        }
        ans = min(ans, que);
    }
    printf("%d\n", ans);
    
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}

