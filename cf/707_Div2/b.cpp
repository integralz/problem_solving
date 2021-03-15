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
    scanf("%d",  &n);
    vector <int> v(n);
    vector <int> ans(n, 0);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    for(int i = n - 1; i >= 0; i--){
        int a = v[i];
        int que = 0;
        bool kk = true;
        if(a > 0){
        while(a--){
            if(i - que >= 0){
            ans[i - que] = 1;
            ++que;
            if(i - que >= 0 && a < v[i - que]){
                i -= que - 1;
                kk = false;
                break;
            }
            }
            else break;
        }
            if(kk){
            i -= que - 1;
            }
        }
    }
    for(int i =0; i < n; ++i){
        printf("%d ", ans[i]);
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



