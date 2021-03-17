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

pair <int, int> mat[5000001];

void solve(){
    int m, n,x, y;
    scanf("%d%d%d%d", &m, &n, &x, &y);
    if(n == y) y = 0;
    for(int i = x; i <= m *n; i += m){
        if(i % n == y){
            printf("%d\n", i);
            return;
        }
    }
    printf("-1\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--)
    solve();
}


