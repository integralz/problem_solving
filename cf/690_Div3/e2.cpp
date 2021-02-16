#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

const int mod = 1000000007;
long long c[200001];
long long inv[200001];

int cal(int a, int b){
    if(a < b) return 0;
    else{
        return c[a] * inv[b] % mod * inv[a - b] % mod;
    }
}

long long make_inv(long long a, int b){
    long long ans = 1;
    while(b){
        if(b % 2 ==0){
            a = a*a % mod;
            b /= 2;
        }
        else{
            ans = ans * a % mod;
            --b;
        }
    }
    return ans;
}

void solve(){
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    vector <long long> v(n);
    for(int i =0; i < n; ++i){
        scanf("%lld", &v[i]);
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    for(int i =0; i < n; ++i){
        int l = upper_bound(v.begin(), v.end(), v[i] + b) - v.begin();
        int num = l - i - 1;
        ans = (ans + cal(num, a - 1)) % mod;
    }
    printf("%lld\n", ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    c[0] = 1;
    inv[0] = 1;
    for(int i =1; i <= 200001; ++i){
        c[i] = c[i - 1] * i % mod;
        inv[i] = make_inv(c[i], mod - 2);
    }
    while(n--){
        solve();
    }
}
