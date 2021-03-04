#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    int cou = 0;
    for(int i =0; i < a - 1; ++i){
        int n, m;
        scanf("%d%d", &n, &m);
        if(n == b || m == b){
            ++cou;
        }
    }
    if(cou == 1 || cou == 0){
        printf("Ayush\n");
        return;
    }
    else{
        if(a % 2 == 0){
            printf("Ayush\n");
            return;
        }
        else{
            printf("Ashish\n");
            return;
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


