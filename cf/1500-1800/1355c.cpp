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
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    ll ans =0;
    for(int i =c; i <= d; ++i){
        int k = i - c + 1;
        if(k >= a && k <= b){
            int g = i - b + 1;
            if(g > b){
                ans += (ll)(b - k + 1) * (b - k + 2) / 2;
            }
            else{
                int q = b - k + 1;
                int w = b - g + 1;
                ans += (ll)(q - w + 1) * (q + w) / 2;
            }
        }
        else if(k < a){
            int g = i - b + 1;
            if(g > b){
                ans += (ll)(b - a + 1) * (b - a + 2) / 2;
                ans += (ll)(a - k) * (b - a + 1);
            }
            else if(g >= a && g <= b){
                ans += (ll)(b * 2 - a - g + 2) * (g - a + 1) /2;
                ans += (ll)(a - k) * (b - a + 1);
            }
            else{
                ans += (ll)(b - a + 1) * (g - k + 1);
            }
        }
    }
    printf("%lld", ans);
}

int main(void){
    solve();
}


