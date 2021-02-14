#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void solve(){
    int n;
    int a;
    scanf("%d", &n);
    int ans = -1;
    
    vector <pair <int, int> > v;
    v.push_back({0,0});
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        v.push_back({a, i + 1});
    }
    for(int i = n; i > 0; --i){
        if(v[i].second + v[i].first > n){
            v[i].second += v[i].first;
        }
        else{
            v[i].second = v[v[i].first + v[i].second].second;
        }
    }
    for(int i = 1; i <= n; ++i){
        if(ans < v[i].second - i){
            ans = v[i].second - i;
        }
    }
    printf("%d\n", ans);
    
}

int main(void){
    int n;
    scanf("%d", &n);
    
    while(n--){
        solve();
    }
}
