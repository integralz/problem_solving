#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main(void){
    int n, q, k;
    scanf("%d%d%d", &n, &q, &k);
    vector <int> v(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    while(q--){
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        if(a == b) printf("%d\n", k - 1);
        else{
            int num = b - a + 1;
            int ans = 0;
            ans -= 4;
            ans -= 3 * (num - 2);
            ans += k;
            ans += v[b] - v[a] + 1;
            ans += (num - 2);
            printf("%d\n", ans);
        }
    }
}
