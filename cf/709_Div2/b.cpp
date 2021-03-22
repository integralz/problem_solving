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
    bool kk = 1;
    if(!kk) printf("0\n");
    else{
        kk = true;
        int que = -1;
        for(int i =0; i < n - 1; ++i){
            if(v[i] <= v[i + 1]){
            
                if(que == -1){
                    que = v[i + 1] - v[i];
                   
                }
                else{
                    if(v[i + 1] - v[i] != que){
                        kk = false;
                        break;
                    }
                }
            }
        }
        if(que == -1){
            bool hh = 1;
            int a1 = v[n - 2] - v[n - 1];
            for(int i = n - 1; i > 0; --i){
                if(a1 != v[i - 1] - v[i]){
                    hh = 0;
                    break;
                }
            }
            if(!hh){
                printf("-1\n");
            }
            else printf("0\n");
            return;
        }
        if(!kk){
            printf("-1\n");
        }
        else{
            int q = -1;
            bool gg = true;
            for(int i =0; i < n - 1; ++i){
                if(v[i] > v[i + 1]){
                    int a = v[i] + que;
                    a -= v[i + 1];
                    if(q == -1){
                        q = a;
                    }
                    else{
                        if(q != a){
                            gg = false;
                            break;
                        }
                    }
                }
            }
            if(!gg) printf("-1\n");
            else{
                gg = true;
                for(int i =0; i < n; ++i){
                    if(v[i] >= q){
                        gg = 0;
                        break;
                    }
                }
                if(q == -1) printf("0\n");
                else if(!gg) printf("-1\n");
                else
                printf("%d %d\n", q, que);
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



