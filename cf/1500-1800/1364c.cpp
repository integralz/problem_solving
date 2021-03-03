#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i = 0;i < n; ++i){
        scanf("%d", &v[i]);
    }
    int k = v[n - 1] + 2;
    vector <int> root(k, 0);
    vector <int> ans(n, -1);
    root[v[0]] = 1;
    for(int i = 1; i < n; ++i){
        root[v[i]] = 1;
        if(v[i] != v[i -1]){
            ans[i] = v[i - 1];
        }
    }
   
    int que = 0;
    for(int i = 0; i < n; ++i){
        if(ans[i] == -1){
            while(que <= v[n - 1] && root[que] == 1){
                ++que;
            }
            ans[i] = que;
            ++que;
        }
        
    }
    for(int i =0; i < n; ++i){
        printf("%d ", ans[i]);
    }
}

int main(void){
    solve();
}

