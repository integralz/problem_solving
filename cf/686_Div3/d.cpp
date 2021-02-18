#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void solve(){
    ll g;
    ll n;
    scanf("%lld", &g);
    n = g;
    map <ll, int> mp;
    int que = 1;
    vector <pair <int, int> > v;
    v.push_back({0, 0});
    for(ll i = 2; i * i <= n; ++i){
        while(n % i == 0){
            if(mp[i] == 0){
                mp[i] = que;
                v.push_back({1, i});
                ++que;
                n /= i;
            }
            else{
                v[mp[i]].first++;
                n /= i;
            }
        }
    }
    if(mp[n] == 0){
        mp[n] = que;
        v.push_back({1, n});
    }
    else{
        v[mp[n]].first++;
    }
    int ans = 0;
    que = 0;
    for(int i = 1; i < v.size(); ++i){
        if(ans < v[i].first){
            ans = v[i].first;
            que = i;
        }
    }
    printf("%d\n", ans);
    ll a = 1;
    for(int i =0; i < ans - 1; ++i){
        printf("%d ", v[que].second);
        a *= v[que].second;
    }
    printf("%lld\n", g / a);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


