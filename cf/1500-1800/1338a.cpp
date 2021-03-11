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
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    int ans = 0;
    int ma = -1987654321;
    for(int i =0; i < n; ++i){
        ma = max(ma, v[i]);
        if(v[i] < ma){
            int a = ma - v[i];
            int cou =0;
            while(a != 0){
                ++cou;
                a /= 2;
            }
            ans = max(ans, cou);
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


