#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
 
void solve(){
    int n;
    int que;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%1d", &v[i]);
    }
    int mat[4] = {2,0,2,0};
    if(v[0] == 2){
        if(v[1] == 0){
            if(v[2] == 2){
                if(v[3] == 0){
                    que = 4;
                }
                else{
                    que = 3;
                }
            }
            else{
                que = 2;
            }
        }
        else{
            que = 1;
        }
    }
    else{
        que = 0;
    }
    for(int i = que; i < 4; ++i){
        if(v[n - 4 + i] != mat[i]){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}
 
int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}
