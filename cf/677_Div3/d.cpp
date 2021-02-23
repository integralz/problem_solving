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
    vector <int> v(n);
    int que = -1;
    int ok = -1;
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
        if(que == -1){
            que = v[i];
        }
        else{
            if(que != v[i]){
                ok = i + 1;
            }
        }
    }
    if(ok > 0){
        printf("YES\n");
        int a = v[0];
        for(int i = 1; i < n; ++i){
            if(a != v[i]){
                printf("%d %d\n", 1, i + 1);
            }
            else{
                printf("%d %d\n", ok, i + 1);
            }
        }
    }
    else{
        printf("NO\n");
    }
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


