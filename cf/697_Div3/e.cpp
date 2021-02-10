#include <iostream>
#include <cstdio>
using namespace std;

int co[1001][1001];

int com(int a, int b){
    if(a == b || b == 0){
        return co[a][b] = 1;
    }
    else if(co[a][b] != 0) return co[a][b];
    return co[a][b] = (com(a - 1, b) + com(a - 1, b - 1)) % (1000000007);
}


void solve(){
    int a, b;
    int g;
    int mat[1001];
    for(int i =0; i < 1001; ++i){
        mat[i] = 0;
    }
    scanf("%d%d", &a, &b);
    for(int i = 0; i < a; ++i){
        scanf("%d", &g);
        mat[g]++;
    }
    for(int i = a; i > 0; --i){
        if(b <= mat[i]){
            printf("%d\n",com(mat[i], b));
            return;
        }
        else{
            b -= mat[i];
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
