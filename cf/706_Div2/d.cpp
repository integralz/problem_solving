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
    vector <int> v(n);
    vector <int> up(n, 0);
    vector <int> down(n, 0);
    map <int, int> mp;
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    for(int i =1; i < n; ++i){
        if(v[i] > v[i - 1]){
            up[i] = up[i - 1] + 1;
        }
        else{
            up[i] = 0;
        }
    }
    for(int i = n - 2; i >= 0; --i){
        if(v[i] > v[i + 1]){
            down[i] = down[i + 1] + 1;
        }
        else{
            down[i] = 0;
        }
    }
    int got = 0;
        int ma =0;
    for(int i =0; i < n; ++i){
        ma= max(ma, up[i]);
        ma = max(ma, down[i]);
    }
    for(int i =0; i < n; ++i){
        if(up[i] == ma){
            if(mp[i] == 0){
                mp[i] = 1;
                ++got;
            }
        }
        if(down[i] == ma){
            if(mp[i] == 0){
                mp[i] = 1;
                ++got;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i < n - 1; ++i){
        if(v[i - 1] < v[i] && v[i] > v[i + 1]){
            int k = max(up[i], down[i]);
            if(k == ma && got < 2){
                int j = min(up[i], down[i]);
                if(k % 2 == 0){
                    --k;
                }
                if(k < j){
                    ++ans;
                }
            }
        }
    }
    
    printf("%d", ans);
    
}

int main(void){
    solve();
}


