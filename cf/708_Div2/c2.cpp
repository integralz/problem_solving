#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
using ll = long long;

void solve(){
    int n, k;
    scanf("%d%d", &n, &k);
    for(int i =0; i < k - 3; ++i){
        printf("%d ", 1);
    }
    n -= (k - 3);
    if(n % 2 == 1){
        printf("%d %d %d\n", n/2,n/2, 1);
    }
    else{
        int a= n / 2;
        if(a % 2 == 0){
            printf("%d %d %d\n", a, a/2, a/2);
        }
        else{
            printf("%d %d %d\n", a - 1, a - 1, 2);
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



