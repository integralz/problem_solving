#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    vector <int> v(a);
    ll a2 = 0;
    for(int i =0; i < a; ++i){
        scanf("%d", &v[i]);
        a2 = max((ll)v[i], a2);
    }
    ll a1 =1;
    ll mid;
    ll got = 1;
    while(a1 <= a2){
        mid = ((ll)a1 + a2)/ 2;
        ll ans = 0;
        for(int i =0 ; i < a; ++i){
            ans += (ll)v[i] / mid;
        }
        if(ans >= b){
            got = max(mid, got);
            a1 = mid + 1;
        }
        else{
            a2 = mid - 1;
        }
    }
    printf("%lld", got);
    
    
}
