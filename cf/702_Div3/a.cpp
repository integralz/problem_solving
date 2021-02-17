#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define long long ll;

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    double a;
    int ans = 0;
    for(int i =0; i < n - 1; ++i){
        if(v[i] > v[i + 1]){
            a = (double)v[i] / v[i + 1];
        }
        else{
            a = (double)v[i + 1] / v[i];
        }
        int q = 0;
        if(a > 2){
            ++q;
            if(a > 4){
                ++q;
                if(a > 8){
                    ++q;
                    if(a > 16){
                        ++q;
                        if(a > 32){
                            ++q;
                        }
                    }
                }
            }
        }
        ans += q;
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
