#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int ans[100000][3];

void solve(){
    int n;
    scanf("%d", &n);
    vector <vector <int> > v(n);
    for(int i =0; i < 2; ++i){
        for(int j =0; j < n; ++j){
            int a;
            scanf("%d", &a);
            v[j].push_back(a);
        }
    }
    ans[0][0] = 0;
    ans[0][1] = v[0][0];
    ans[0][2] = v[0][1];
    for(int i = 1; i < n; ++i){
        int b = max(ans[i -1][0], ans[i - 1][1]);
        b = max(b, ans[i - 1][2]);
        ans[i][0] = b;
        ans[i][1] = max(ans[i - 1][0], ans[i - 1][2]);
        ans[i][1] += v[i][0];
        ans[i][2] = max(ans[i - 1][0], ans[i - 1][1]);
        ans[i][2] += v[i][1];
    }
    int cou = 0;
    for(int i =0; i < 3; ++i){
        if(cou < ans[n - 1][i]){
            cou = ans[n - 1][i];
        }
    }
    printf("%d\n", cou);
    
}


int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}
