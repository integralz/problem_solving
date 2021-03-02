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
    int n; int tar;
    scanf("%d%d", &n, &tar);
    vector <int> v(n);
    int su = 0;
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
        su += v[i];
    }
    if(su == tar) printf("YES\n");
    else printf("NO\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


