#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

void solve(){
    int n;
    int a;
    long long ans = 0;
    scanf("%d", &n);
    vector <int> v(n + 1, 0);
    for(int i =0;i < n; ++i){
        scanf("%d", &a);
        v[a]++;
    }
    for(int i = 1; i <= n - 2; ++i){
        if(v[i] > 0 && v[i + 1] > 0 && v[i + 2] > 0){
            ans += (long long)v[i] * v[i + 1] * v[i + 2];
        }
        if(v[i] >= 2 && v[i + 2] >= 1){
            ans += ((long long)v[i] * (v[i] - 1) / 2) * v[i + 2];
        }
        if(v[i] >= 1 && v[i + 2] >= 2){
            ans += ((long long)v[i + 2] * (v[i + 2] - 1) / 2) * v[i];
        }
    }
    for(int i = 1; i <= n - 1; ++i){
        if(v[i] >= 2 && v[i + 1] >= 1){
            ans += ((long long)v[i] * (v[i] - 1) / 2) * v[i + 1];
        }
        if(v[i] >= 1 && v[i + 1] >= 2){
            ans += ((long long)v[i + 1] * (v[i + 1] - 1) / 2) * v[i];
        }
    }
    for(int i = 1; i <= n; ++i){
        if(v[i] >= 3){
            ans += (long long)v[i] *(v[i] - 1) * (v[i] - 2) / 6;
        }
    }
    printf("%lld\n", ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}

