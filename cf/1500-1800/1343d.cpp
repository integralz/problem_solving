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
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> v(n);
    map <int, int> mp;
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    vector <int> su(2*m + 2, 0);
    for(int i =0; i < (n/2); ++i){
        int a = max(v[i], v[n - 1 - i]);
        int b= min(v[n - 1 - i], v[i]);
        su[b + 1]++;
        su[a + m + 1]--;
        mp[a + b]++;
    }
    for(int i =1; i < 2*m + 2; ++i){
        su[i] += su[i - 1];
    }
    int ans = (n/2);
    for(int i = 0; i < 2*m + 1; ++i){
        int a = mp[i];
        int b = su[i];
        b -= mp[i];
        int c = (n/2) - (a + b);
        c *= 2;
        c += b;
        ans = min(ans, c);
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


