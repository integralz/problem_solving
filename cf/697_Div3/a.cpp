#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
    int num;
    long long a;
    scanf("%d", &num);
    while(num--){
        scanf("%lld", &a);
        while(1){
            if(a == 1){
                printf("NO\n");
                break;
            }
            if(a % 2 == 1){
                printf("YES\n");
                break;
            }
            else a /= 2;
        }
    }
}
