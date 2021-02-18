#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;
ll mat[31][31];

ll comb(int a, int b){
    if(mat[b][a] != 0) return mat[b][a];
    if(a == 0 || a == b) return mat[b][a] = 1;
    else return mat[b][a] = comb(a, b - 1) + comb(a - 1, b - 1);
}

void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    printf("%lld\n", comb(a, b));
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}
