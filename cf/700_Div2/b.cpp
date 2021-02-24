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
    int a,c;
    ll b;
    scanf("%d%lld%d", &a, &b, &c);
    vector <int> v(c);
    vector <int> h(c);
    for(int i =0;  i < c; ++i){
        scanf("%d", &v[i]);
    }
    for(int i =0; i < c; ++i){
        scanf("%d", &h[i]);
    }
    int ma = 0;
    int que = 0;
    for(int i =0; i < c; ++i){
        if(ma < v[i]){
            ma = v[i];
            que = i;
        }
    }
    for(int i = 0; i < c; ++i){
        if(i == que) continue;
        else{
            int k = ceil((double)h[i] / a);
            b -= (ll)k * v[i];
            if(b <= 0){
                printf("NO\n");
                return;
            }
        }
    }
    int k = floor((double)(h[que] - 1) / a);
    b -= (ll)k * v[que];
    if(b <= 0){
        printf("NO\n");
        return;
    }
    printf("YES\n");
    
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


