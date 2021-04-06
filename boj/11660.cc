#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
    vector <vector <int> > v(n, vector <int>(n));
    vector <vector <int> > ans(n + 1, vector <int> (n + 1));
    for(int i =0; i < n; ++i){
        for(int j =0; j < n; ++j){
            scanf("%d", &v[i][j]);
        }
    }
    for(int i = 1; i < n + 1; ++i){
        for(int j = 1; j < n + 1; ++j){
            ans[i][j] = ans[i - 1][j] + ans[i][j - 1] - ans[i - 1][j - 1] + v[i - 1][j - 1];
        }
    }
    while(m--){
        int a, b, c, d;
        scanf("%d%d%d%d", &a, &b, &c, &d);
        --a; --b; --c; --d;
        printf("%d\n", ans[c + 1][d + 1] - ans[c + 1][b] - ans[a][d + 1] + ans[a][b]);
    }
    
}
