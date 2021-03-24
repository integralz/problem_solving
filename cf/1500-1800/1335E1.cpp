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

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    vector <vector <int> > ans(27, vector <int> (n));
    for(int i =0; i < n; ++i){
        for(int j =0; j < 27; ++j){
            ans[j][i] =0;
        }
    }
    ans[v[0]][0]++;
  

    for(int i =1; i < n; ++i){
        for(int j =0; j < 27; ++j){
            ans[j][i] = ans[j][i - 1];
        }
        ++ans[v[i]][i];
    }

    int answer = 0;
    for(int i =0 ; i < 27; ++i){
        int cou =0;
        for(int j =0; j < n; ++j){
            if(v[j] == i)++cou;
        }
        answer = max(answer, cou);
    }
    for(int i =0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int a =0;
            int b =0;
            for(int k = 1; k < 27; ++k){
                a = max(ans[k][j - 1] - ans[k][i], a);
                b = max(b, min(ans[k][i], ans[k][n - 1] - ans[k][j - 1]));
            }
            answer = max(answer, a + 2*b);
        }
    }
    printf("%d\n", answer);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


