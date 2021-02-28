#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

using ll = long long;
int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    vector <ll> v(a);
    for(int i =0; i < a; ++i){
        scanf("%lld", &v[i]);
    }
    ll got = -1;
    ll ans =0;
    ll a1 = 0;
    ll a2 = 1000000000;
    ll mid;
    while(a1 <= a2){
        mid = (a1 + a2)/ 2;
        ans = 0;
        for(int i =0; i < a; ++i){
            if(mid < v[i]){
                ans += v[i] - mid;
            }
        }
        if(ans >= (ll)b){
            got = max(got, mid);
            a1 = mid + 1;
        }
        else{
            a2 = mid - 1;
        }
    }
    printf("%lld", got);
}
