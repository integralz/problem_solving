#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    int ans = 0;
    for(int i =0; i < n; ++i){
        ans = max(ans, v[i]);
    }
    int cou = 0;
    for(int i =0; i < n; ++i){
        if(v[i] == ans) ++cou;
    }
    if(cou == n) printf("-1\n");
    else{
        for(int i =0; i < n; ++i){
            if(v[i] == ans){
                if(i - 1 >= 0){
                    if(v[i] != v[i -1]){
                        printf("%d\n", i + 1);
                        return;
                    }
                }
                if(i + 1 < n){
                    if(v[i] != v[i + 1]){
                        printf("%d\n", i + 1);
                        return;
                    }
                }
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


