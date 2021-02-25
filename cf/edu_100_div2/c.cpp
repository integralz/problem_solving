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
    int n;
    scanf("%d", &n);
    vector <pair <ll, int> > v(n);
    for(int i =0;i < n; ++i){
        scanf("%lld%d", &v[i].first, &v[i].second);
    }
    
    ll que = v[0].first + abs(v[0].second);
    int a = 0;
    int b = v[0].second;
    int ans = 0;
    for(int i =0; i < n - 1; ++i){
        if(v[i].first >= que){
            que = v[i].first + abs(b - v[i].second);
            a = b;
            b = v[i].second;
        }
        if(v[i + 1].first >= que){
            if(b > a){
                int b1 = b;
                int a1 = b - (que - v[i].first);
                if(a1 <= v[i].second && v[i].second <= b1){
                    ++ans;
                }
            }
            else{
                int b1 = b;
                int a1 = b + (que - v[i].first);
                if(b1 <= v[i].second && v[i].second <= a1){
                    ++ans;
                }
            }
        }
        else{
            if(b > a){
                int a1 = b - (que - v[i].first);
                int b1 = b - (que - v[i + 1].first);
                if(a1 <= v[i].second && v[i].second <= b1){
                    ++ans;
                }
            }
            else{
                int a1 = b + (que - v[i].first);
                int b1 = b + (que - v[i + 1].first);
                if(b1 <= v[i].second && v[i].second <= a1) ++ans;
            }
        }
    }
    if(que > v[n - 1].first){
        if(a < b){
            int a1 = b - (que - v[n-1].first);
            if(a1 <= v[n - 1].second && v[n - 1].second <= b) ++ans;
        }
        else{
            int a1 = b + (que - v[n - 1].first);
            if(b <= v[n - 1].second && v[n - 1].second <= a1) ++ans;
        }
    }
    else{
        ++ans;
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



