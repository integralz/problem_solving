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
    ll answer = 2000000000000000000;
    int r, g, b1;
    scanf("%d%d%d", &r, &g, &b1);
    vector <int> v1(r);
    vector <int> v2(g);
    vector <int> v3(b1);
    for(int i =0; i < r; ++i){
        scanf("%d", &v1[i]);
    }
    for(int i =0; i < g; ++i){
        scanf("%d", &v2[i]);
    }
    for(int i =0; i < b1; ++i){
        scanf("%d", &v3[i]);
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    sort(v3.begin(), v3.end());
    for(int i =0; i < r; ++i){
        int a = lower_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
        int b = upper_bound(v3.begin(), v3.end(), v1[i]) - v3.begin();
        if(a == g || b == 0) continue;
        int q = v2[a];
        int w = v3[b - 1];
        int z = v1[i];
        ll ans = ((ll)q - w) * ((ll)q - w) + ((ll)q - z) *((ll)q - z) + ((ll)w - z)*((ll)w - z);
        answer =    min(answer, ans);
    }
    for(int i =0; i < r; ++i){
        int a = lower_bound(v3.begin(), v3.end(), v1[i]) - v3.begin();
        int b = upper_bound(v2.begin(), v2.end(), v1[i]) - v2.begin();
        if(a == b1 || b == 0) continue;
        int q = v3[a];
        int w = v2[b - 1];
        int z = v1[i];
        ll ans = ((ll)q - w) * ((ll)q - w) + ((ll)q - z) *((ll)q - z) + ((ll)w - z)*((ll)w - z);
        answer =    min(answer, ans);
    }
    for(int i =0; i < g; ++i){
        int a = lower_bound(v1.begin(), v1.end(), v2[i]) - v1.begin();
        int b = upper_bound(v3.begin(), v3.end(), v2[i]) - v3.begin();
        if(a == r || b == 0) continue;
        int q = v1[a];
        int w = v3[b - 1];
        int z = v2[i];
        ll ans = ((ll)q - w) * ((ll)q - w) + ((ll)q - z) *((ll)q - z) + ((ll)w - z)*((ll)w - z);
        answer =    min(answer, ans);
    }
    for(int i =0; i < g; ++i){
        int a = lower_bound(v3.begin(), v3.end(), v2[i]) - v3.begin();
        int b = upper_bound(v1.begin(), v1.end(), v2[i]) - v1.begin();
        if(a == b1 || b == 0) continue;
        int q = v3[a];
        int w = v1[b - 1];
        int z = v2[i];
        ll ans = ((ll)q - w) * ((ll)q - w) + ((ll)q - z) *((ll)q - z) + ((ll)w - z)*((ll)w - z);
        answer =    min(answer, ans);
    }
    for(int i =0; i < b1; ++i){
        int a = lower_bound(v1.begin(), v1.end(), v3[i]) - v1.begin();
        int b = upper_bound(v2.begin(), v2.end(), v3[i]) - v2.begin();
        if(a == r || b == 0) continue;
        int q = v1[a];
        int w = v2[b - 1];
        int z = v3[i];
        ll ans = ((ll)q - w) * ((ll)q - w) + ((ll)q - z) *((ll)q - z) + ((ll)w - z)*((ll)w - z);
        answer =    min(answer, ans);
    }
    for(int i =0; i < b1; ++i){
        int a = lower_bound(v2.begin(), v2.end(), v3[i]) - v2.begin();
        int b = upper_bound(v1.begin(), v1.end(), v3[i]) - v1.begin();
        if(a == g || b == 0) continue;
        int q = v2[a];
        int w = v1[b - 1];
        int z = v3[i];
        ll ans = ((ll)q - w) * ((ll)q - w) + ((ll)q - z) *((ll)q - z) + ((ll)w - z)*((ll)w - z);
        answer =    min(answer, ans);
    }
    printf("%lld\n", answer);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


