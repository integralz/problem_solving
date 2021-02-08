#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
    int num;
    int a, b, c;
    int p;
    int ans;
    scanf("%d", &num);
    
    for(int i = 0; i < num; ++i){
        scanf("%d%d%d",&a, &b, &c);
        if(a > b){
            p = b;
            b = a;
            a = p;
        }
        b = b - a;
        ans = b / c;
        if(b % c != 0) ++ans;
        printf("%d\n", ans);
    }
}
