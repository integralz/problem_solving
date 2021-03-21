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

int mat[20000001];
int root[20000001];
void solve(){
    int c, d, x;
    ll ans = 0;
    scanf("%d%d%d", &c, &d, &x);
    for(int i = 1; i * i <= x; ++i){
        if(x % i == 0){
            int a= x / i;
            if((a + d) % c == 0){
                int got = (a + d) / c;
                ans += 1 << root[got];
            }
            if(x / i != i)
            if((i + d) % c == 0){
                int got = (i + d) / c;
                ans += 1 << root[got];
            }
        }
    }
    printf("%lld\n", ans);
}

int main(void){
    int n;
    for(int i =2; i < 20000001; ++i){
        if(mat[i] == 0){
            for(int j = i; j < 20000001; j += i){
                if(mat[j] == 0){
                    mat[j] = i;
                }
            }
        }
    }
    
    for(int i = 2; i < 20000001; ++i){
        int a = i / mat[i];
        int que = 0;
        if(mat[i] != mat[a]) que = 1;
        root[i] = root[a] + que;
    }
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


