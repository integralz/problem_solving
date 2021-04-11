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
    int n, l, r, s;
    scanf("%d%d%d%d", &n, &l, &r, &s);
    int a = r - l + 1;
    int ans = 0;
    for(int i = 1; i <= a; ++i){
        ans += n - i + 1;
    }
    if(ans < s){
        printf("-1\n");
        return;
    }
    ans = 0;
    for(int i = 1; i <= a; ++i){
        ans += i;
    }
    if(ans > s){
        printf("-1\n");
        return;
    }
    vector <int> v(a);
   
    for(int i =0; i < a; ++i){
        v[i] = i + 1;
    }
    int que = n - a;
    for(int i = a - 1; i >= 0; --i){
        if(ans + que >= s){
            int g = s - ans;
            v[i] += g;
            break;
        }
        else{
            ans += que;
            v[i] += que;
        }
    }
    
    map <int, int> mp;
    for(int i =0; i < a; ++i){
        mp[v[i]] = 1;
    }
    int cou = 0;
    que = 1;
    for(int i =1; i <= n + 1; ++i){
        if(cou == l - 1){
            que = i;
            break;
        }
        if(mp[i] == 0){
            ++cou;
            printf("%d ", i);
        }
    }
    for(int i =0; i < a; ++i){
        printf("%d ", v[i]);
    }
    for(int i = que; i <= n; ++i){
        if(mp[i] == 0){
            printf("%d ", i);
        }
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



