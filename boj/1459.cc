#include <iostream>
#include <cstdio>
using namespace std;

using ll = long long;

int main(void){
    ll x, y, w, s;
    scanf("%lld%lld%lld%lld", &x, &y, &w, &s);
    if(2 * w <= s){
        printf("%lld", w * (x + y));
    }
    else if(w > s){
        ll que = min(x, y);
        ll que1 = max(x, y);
        printf("%lld", s * que + (que1 - que) % 2 * w + (que1 - que) / 2 * s * 2 );
    }
    else{
        ll que = min(x, y);
        ll que1 = max(x, y);
        printf("%lld", s * que + w * (que1 - que));
    }
}
