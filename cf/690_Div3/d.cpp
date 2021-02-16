#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    int su = 0;
    for(int i =0 ; i < n; ++i){
        scanf("%d", &v[i]);
        su += v[i];
    }
    int que = 0;
    for(int i = 0; i < n; ++i){
        que += v[i];
        if(su % que == 0){
            int a = 0;
            int ans = 1;
            int last = i;
            for(int j = i + 1; j < n; ++j){
                a += v[j];
                if(a > que) break;
                else if(a == que){
                    ++ans;
                    last = j;
                    a = 0;
                }
            }
            if(last == n - 1){
                printf("%d\n", n - ans);
                return;
            }
        }
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


