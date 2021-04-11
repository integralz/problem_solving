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
    int a= v[0];
    int b = v[1];
    if(a != b){
    if(a != v[2]){
        printf("%d\n", 1);
    }
    else{
        printf("%d\n", 2);
    }
    }
    else{
        for(int i = 2; i < n; ++i){
            if(v[i] != a){
                printf("%d\n", i + 1);
                return;
            }
        }
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



