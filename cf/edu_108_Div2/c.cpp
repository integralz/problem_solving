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

bool gg(int a, int b){
    return a > b;
}

bool qq(vector <ll> a, vector <ll> b){
    return (int)a.size() < (int)b.size();
}

void solve(){
    int n;
    scanf("%d", &n);
    vector <vector <ll> > v(n + 1);
    vector <int> a1(n);
    vector <int> a2(n);
    int ma = 0;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a1[i]);
    }
    
    for(int i = 0; i < n; ++i){
        scanf("%d", &a2[i]);
    }
    
    for(int i = 0; i <= n; ++i){
        v[i].push_back(0);
    }
    
    for(int i = 0; i < n; ++i){
        v[a1[i]].push_back(a2[i]);
    }
    
    for(int i = 0; i <= n; ++i){
        sort(v[i].begin() + 1, v[i].end(), gg);
        ma = max(ma, (int)v[i].size());
    }
    
    for(int i = 0; i <= n; ++i){
        int kk = (int)v[i].size();
        for(int j =1; j < kk; ++j){
            v[i][j] += v[i][j - 1];
        }
    }
    
    sort(v.begin(), v.end(), qq);
    --ma;
    for(int i = 1; i <= ma; ++i){
        ll ans = 0;
        for(int j = n; j >= 1; --j){
            int kk = (int)v[j].size() - 1;
            kk /= i;
            kk *= i;
            if(kk == 0) break;
            ans += v[j][kk];
        }
        printf("%lld ", ans);
    }
    for(int i = ma; i < n; ++i){
        printf("0 ");
    }
    printf("\n");
    
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



