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
    int que = 1;
    map <int, int> mp;
    vector <int> v(n + 1, 0);
    for(int i =0; i < n; ++i){
        int a;
        scanf("%d", &a);
        if(mp[a] == 0){
            mp[a] = que;
            v[que]++;
            ++que;
        }
        else{
            v[mp[a]]++;
        }
    }
    sort(v.begin() + 1, v.begin() + que);
    int ans = n;
    for(int i = 1; i < que; ++i){
        int su = (que - i) * v[i];
        ans = min(ans, n - su);
        for(int j = i + 1; j < que; ++j){
            if(v[j] == v[i]){
                i = j;
            }
            else break;
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

