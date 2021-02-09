#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
    int num;
    int a;
    int b, c;
    scanf("%d", &num);
    while(num--){
        scanf("%d", &a);
        b = a / 2020;
        c = a % 2020;
        if(b >= c){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
