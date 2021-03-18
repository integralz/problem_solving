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
    int ans = 0;
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> v(m, 0);
    for(int i =0; i < n; ++i){
        int a;
        scanf("%d", &a);
        v[a % m]++;
    }
    int q = (m - 1) / 2;
    if(v[0] != 0){
        ++ans;
    }
    for(int i =1; i <= q; ++i){
        int a = v[i];
        int b = v[m - i];
        if(a == 0 && b == 0) continue;
        
        ++ans;
        int que = min(a, b);
        a -= que;
        b -= que;
        if(a > 1){
            ans += a - 1;
        }
        else if(b > 1){
            ans += b - 1;
        }
    }
    if(m % 2 == 0){
        int a = m / 2;
        if(v[a] !=0){
            ++ans;
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



