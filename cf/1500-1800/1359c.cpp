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
    int h, c, t;
    scanf("%d%d%d", &h, &c, &t);
    if((double)t <= ((double)h + c) / 2){
        printf("2\n");
    }
    else{
        int a = (t - c) / (t * 2 - h- c);
        int b = a + 1;
        int cal = h + c - 2 * t;
        int got = t - c;
        if(abs(((ll)a*cal + got)*(2*b - 1)) <= abs(((ll)b*cal + got))*(2*a - 1)){
            printf("%d\n", 2*a - 1);
        }
        else{
            printf("%d\n", 2*b - 1);
        }
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}




