#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void solve(){
    int q,w;
    scanf("%d%d", &q, &w);
    int a = 0;
    int b = 100000;
    int mid =0;
    while(a <= b){
        mid = (a + b) / 2;
        if((long long)mid * mid < (long long)q){
            a = mid + 1;
        }
        else if((long long)mid * mid > (long long)q){
            b = mid - 1;
        }
        else{
            break;
        }
    }
    long long ans = 0;
    for(int i = 1 ; i <= mid; ++i){
        int che = q;
        che -= i;
        che /= i;
        if(che > i){
            if(che > w){
                if(w > i){
                    ans += w - i;
                }
            }
            else{
                ans += che - i;
            }
        }
    }
    printf("%lld\n", ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}

