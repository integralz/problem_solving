#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

vector <long long> mat(10001);

void solve(){
    long long n;
    scanf("%lld", &n);
    
    for(int i = 1; i < 10001; ++i){
        long long v = n;
        if(mat[i] > v){
            break;
        }
        else{
            v -= mat[i];
            int kk = lower_bound(mat.begin(), mat.end(), v) - (mat.begin());
            if(mat[kk] == v && kk != 0){
                printf("YES\n");
                return;
            }
        }
    }
    printf("NO\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    
    for(int i = 1; i < 10001; ++i){
        mat[i] = (long long)i * i * i;
    }
    while(n--){
        solve();
    }
}


