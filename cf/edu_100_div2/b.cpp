#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;
int mat[32];
void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i=0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    for(int i =0; i < n; ++i){
        for(int j = 0; j < 32; ++j){
            if(v[i] < mat[j]){
                printf("%d ", mat[j - 1]);
                break;
            }
        }
    }
    printf("\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    mat[0] = 1;
    for(int i =1; i < 32;++i){
        mat[i] = mat[i -1] * 2;
    }
    while(n--){
        solve();
    }
}


