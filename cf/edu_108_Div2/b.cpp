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
    int x, y, cost;
    scanf("%d%d%d", &x, &y, &cost);
    --x;
    --y;
    int que = 0;
    que += x;
    que += (x + 1) * y;
    if(que == cost){
        printf("YES\n");
    }
    else printf("NO\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



