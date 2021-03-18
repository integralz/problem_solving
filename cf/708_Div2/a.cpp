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
    map <int, int> mp;
    for(int i=0 ; i < n; ++i){
        scanf("%d", &v[i]);
        mp[v[i]]++;
    }
    int que = 0;
    while(mp[que] != 0){
        printf("%d ", que);
        mp[que]--;
        ++que;
    }
    for(int i =0; i <= 100; ++i){
        int a = mp[i];
        for(int j =0; j < a; ++j){
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



