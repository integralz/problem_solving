#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

void solve(){
    int n;
    int que = 0;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    for(int i = 0; i < n/2; ++i){
        printf("%d ", v[que]);
        printf("%d ", v[n - que - 1]);
        ++que;
    }
    if(n % 2 == 1){
        printf("%d", v[que]);
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
