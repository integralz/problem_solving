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
    int n, a;
    scanf("%d%d", &n, &a);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    ll ans = 0;
    for(int i =0; i < n; ++i){
        ans += v[i];
        if(ans == (ll)a){
            if(i < n - 1){
                printf("YES\n");
                for(int j = 0; j < i; ++j){
                    printf("%d ", v[j]);
                }
                printf("%d ", v[i + 1]);
                printf("%d ", v[i]);
                for(int j = i + 2; j <n; ++j){
                    printf("%d ", v[j]);
                }
                printf("\n");
                return;
            }
            else{
                printf("NO\n");
                return;
            }
        }
    }
    printf("YES\n");
    for(int i =0; i< n; ++i){
        printf("%d ", v[i]);
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



