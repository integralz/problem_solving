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
    vector <pair <int, int> > v1;
    vector <pair <int, int> > v2;
    vector <int> mi1((n + 1)/2, 0);
    vector <int> mi2(n/2, 0);
    vector <ll> su1((n + 1)/2);
    vector <ll> su2(n/2);
    for(int i =0; i < n; ++i){
        int a;
        scanf("%d", &a);
        if(i % 2 == 0){
            v1.push_back({a, i / 2});
        }
        else{
            v2.push_back({a, (i - 1)/2});
        }
    }
    int que = 0;
    int q = v2[0].first;
    for(int i = 1; i < n/2; ++i){
        if(v2[i].first < q){
            que = i;
            q = v2[i].first;
        }
        mi2[i] = que;
    }
    
    su1[0] = (ll)v1[0].first;
    su2[0] = (ll)v2[0].first;
    for(int i =1; i < n / 2; ++i){
        su2[i] = su2[i - 1] + v2[i].first;
    }
    int m = (n + 1) / 2;
    
    que =0;
    q = v1[0].first;
    for(int i = 1; i < m; ++i){
        if(v1[i].first < q){
            que = i;
            q = v1[i].first;
        }
        mi1[i] = que;
    }
    
    for(int i = 1; i < m;++i){
        su1[i] = su1[i - 1] + v1[i].first;
    }
    ll ans = 100000000000000000;
    for(int i =0;i < 1; ++i){
        ll su = 0;
        int a = mi1[i];
        su += ((ll)n - i) * v1[a].first;
        if(a != 0){
            su += su1[a - 1];
        }
        if(a != i){
            su += su1[i] - su1[a];
        }
        ll ssu = su;
        int b = mi2[i];
        ssu += ((ll)n - i) * v2[b].first;
        if(b !=0){
            ssu += su2[b - 1];
        }
        if(b != i){
            ssu += su2[i - 1] - su2[b];
        }
        ans = min(ans, ssu);
    }
    for(int i = 1; i < m - 1; ++i){
        ll su = 0;
        int a = mi1[i];
        su += ((ll)n - i) * v1[a].first;
        if(a != 0){
            su += su1[a - 1];
        }
        if(a != i){
            su += su1[i] - su1[a];
        }
        //dd
        ll ssu = su;
        int b = mi2[i - 1];
        ssu += ((ll)n - i + 1) * v2[b].first;
        if(b !=0){
            ssu += su2[b - 1];
        }
        if(b != i - 1){
            ssu += su2[i - 1] - su2[b];
        }
        ans = min(ans, ssu);
        //dd
        ssu = su;
        b = mi2[i];
        ssu += ((ll)n - i) * v2[b].first;
        if(b !=0){
            ssu += su2[b - 1];
        }
        if(b != i){
            ssu += su2[i] - su2[b];
        }

        ans = min(ans, ssu);
    }
    if(m != 1){
    for(int i = m - 1; i < m; ++i){
        ll su = 0;
        int a = mi1[i];
      
        su += ((ll)n - i) * v1[a].first;
        
        if(a != 0){
            su += su1[a - 1];
        }
        if(a != i){
            su += su1[i] - su1[a];
        }
        ll ssu = su;
        
        int b = mi2[i - 1];
        ssu += ((ll)n - i + 1) * v2[b].first;
        if(b !=0){
            ssu += su2[b - 1];
        }
        if(b != i - 1){
            ssu += su2[i - 1] - su2[b];
        }
        ans = min(ans, ssu);
        if((n/2) == m){
            ssu = su;
            b = mi2[i];
            ssu += ((ll)n - i) * v2[b].first;
            if(b !=0){
                ssu += su2[b - 1];
            }
            if(b != i){
                ssu += su2[i] - su2[b];
            }
            ans = min(ans, ssu);
        }
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


