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
    int r, b, d;
    scanf("%d%d%d", &r, &b, &d);
    int q = min(r, b);
    int que = max(r, b);
    if((ll)q * (d + 1) >= que){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



