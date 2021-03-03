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
    int n, m;
    scanf("%d%d", &n, &m);
    vector <vector <int> > v(n, vector <int> (m));
    for(int i = 0; i < n; ++i){
        for(int j =0 ; j < m; ++j){
            scanf("%d", &v[i][j]);
        }
    }
    vector <vector <int> > ans(n + m - 1, vector <int> (2));
    for(int i =0; i < n + m - 1; ++i){
        for(int j =0; j < 2; ++j){
            ans[i][j] = 0;
        }
    }
    for(int i =0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(v[i][j] == 0){
                ans[i + j][0]++;
            }
            else{
                ans[i + j][1]++;
            }
        }
    }
    int k = (m + n - 3) / 2;
    int an = 0;
    for(int i = 0; i <= k; ++i){
        an += min(ans[i][0] + ans[m + n - 2 - i][0],ans[i][1] + ans[m + n - 2 - i][1]);
    }
    printf("%d\n", an);
    
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


