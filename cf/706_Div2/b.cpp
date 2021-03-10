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
    int n, k;
    scanf("%d%d", &n, &k);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end());
    if(k == 0){
        printf("%d\n", n);
    }
    else{
        int que = 0;
        for(int i =0; i < n; ++i){
            if(que != v[i]){
                break;
            }
            else{
                que++;
            }
        }
        int q;
        if((que + v[n - 1]) % 2 ==0){
            q = (que + v[n-1]) /2;
            
        }
        else{
            q = (que + v[n - 1]) /2 + 1;
        }
       
        if(q == que){
            printf("%d\n", n + k);
        }
        else{
            bool kk = true;
            for(int i =0; i < n; ++i){
                if(q == v[i]){
                    kk = false;
                    break;
                }
            }
            if(kk){
                printf("%d\n", n + 1);
            }
            else{
                printf("%d\n", n);
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



