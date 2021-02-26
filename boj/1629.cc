#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
    long long a, b, c;
    scanf("%lld%lld%lld", &a, &b, &c);
    a %= c;
    long long ans = 1;
    while(b != 0){
        if(b % 2 == 0){
            a *= a;
            a %= c;
            b /= 2;
        }
        else{
            ans *= a;
            ans %= c;
            b--;
        }
    }
    printf("%lld", ans);
}
