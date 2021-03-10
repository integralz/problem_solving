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
    int n, k;
    scanf("%d%d", &n, &k);
    string s;
    cin >> s;
    if(k ==0){
        printf("YES\n");
    }
    else{
        bool kk = true;
        if(n > 2*k){
            for(int i =0; i < k; ++i){
                if(s[i] != s[n - 1 - i]){
                    kk= false;
                    break;
                }
            }
            if(kk){
                printf("YES\n");
            }
            else{
                printf("NO\n");
            }
        }
        else{
            printf("NO\n");
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



