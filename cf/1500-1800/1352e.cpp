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
    int ans =0;
    for(int i =0;i< n; ++i){
        int tar = v[i];
        int a= 0;
        int b= 0;
        int que = v[0];
        while(a < n && b < n){
            if(que == tar){
                if(b != a){
                    ++ans;
                    break;
                }
                else{
                    ++b;
                    que += v[b];
                }
            }
            else if(que < tar){
                ++b;
                que += v[b];
            }
            else{
                que -= v[a];
                ++a;
            }
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


