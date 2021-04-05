#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> v(n);
    vector <int> ans(n + 1, 0);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    for(int i = 1; i < n + 1; ++i){
        ans[i] = ans[i - 1] + v[i - 1];
    }
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        printf("%d\n", ans[b + 1] - ans[a]);
        
    }
}
