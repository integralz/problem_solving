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
    ll n;
    scanf("%lld", &n);
    vector <int> v(10, 1);
    char ch[10] = {'c','o','d','e','f','o','r','c','e','s'};
    if(n == 1){
        for(int i =0; i < 10; ++i){
            printf("%c", ch[i]);
        }
        return;
    }
    while(1){
        for(int i =0; i < 10; ++i){
            v[i]++;
            ll ans = 1;
            for(int j =0; j < 10; ++j){
                ans *= (ll)v[j];
            }
            if(ans >= n){
                for(int k =0; k < 10; ++k){
                    for(int h = 0; h < v[k]; ++h){
                        printf("%c", ch[k]);
                    }
                }
                return;
            }
        }
    }
}

int main(void){
    solve();
}


