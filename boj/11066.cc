#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int mat[500][500];

int dp(vector <int> &v,vector <int> &su, int st, int end){
    if(end < st) return 0;
    if(st == end) return 0;
    if(st + 1 == end) return mat[st][end] = v[st] + v[end];
    if(mat[st][end] != 0) return mat[st][end];
    int ans = 987654321;
    for(int i = st; i < end; ++i){
        ans = min(dp(v, su,st, i) + dp(v,su, i + 1, end) + su[end + 1] - su[st], ans);
    }
    return mat[st][end] = ans;
}
void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    vector <int> su(n + 1, 0);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    su[1] = v[0];
    for(int i = 2;i <= n; ++i){
        su[i] = v[i - 1] + su[i - 1];
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            mat[i][j] = 0;
        }
    }
    int ans = dp(v,su, 0, n - 1);
    printf("%d\n", ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}
