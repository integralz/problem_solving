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
    int n;
    scanf("%d", &n);
    vector <int> v(n + 2);
    ll ans = 0;
    for(int i =0; i < n + 2; ++i){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    for(int i =0; i < n; ++i){
        ans += v[i];
    }
    if(ans == v[n]){
        for(int i =0; i < n; ++i){
            printf("%d ", v[i]);
        }
        printf("\n");
        return;
    }
    ans += v[n];
    for(int i =0; i < n + 1; ++i){
        ll q = ans - v[i];
        if(q == v[n + 1]){
            for(int j = 0; j < n + 1; ++j){
                if(j != i){
                    printf("%d ", v[j]);
                }
            }
            printf("\n");
            return;
        }
    }
    
    
    printf("-1\n");
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



