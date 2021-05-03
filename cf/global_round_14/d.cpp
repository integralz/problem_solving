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
    int n, l, r;
    scanf("%d%d%d", &n, &l, &r);
    vector <pair <int, int> > v(n);
    int ans = 0;
    for(int i =0 ; i < n; ++i){
        v[i].first = 0;
        v[i].second = 0;
    }
    for(int i =0 ; i < l; ++i){
        int a;
        scanf("%d", &a);
        --a;
        v[a].first++;
    }
    for(int i =0 ; i < r; ++i){
        int a;
        scanf("%d", &a);
        --a;
        v[a].second++;
    }
    for(int i =0 ; i < n; ++i){
        int a = min(v[i].first, v[i].second);
        v[i].first -= a;
        v[i].second -= a;
        ans += a;
    }
    
    int gap = n/2 - min(l, r);
    
    ll qq = 0;
    int aa = 0;
    if(l < r){
        for(int i =0 ; i < n; ++i){
            aa += v[i].second / 2;
        }
    }
    else{
        for(int i =0 ; i < n; ++i){
            aa += v[i].first / 2;
        }
    }

    
    if(aa >= gap){
        qq += gap;
        ans += gap;
        gap = 0;
    }
    else{
        qq += aa;
        ans += aa;
        gap -= aa;
    }

    qq += gap;
    qq += (n / 2) - ans;
    
    printf("%lld\n", qq);

}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



