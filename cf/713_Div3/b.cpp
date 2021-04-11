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
    vector <int> v(4, -1);
    vector <vector <int> >ans(n, vector <int> (n));
    for(int i =0; i < n; ++i){
        for(int j =0; j < n; ++j){
            ans[i][j] = 0;
        }
    }
    for(int i =0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            char a;
            scanf("%c", &a);
            if(a == '\n'){
                scanf("%c", &a);
            }
            if(a == '*'){
                if(v[0] == -1){
                    v[0] = i;
                    v[1] = j;
                }
                else{
                    v[2] = i;
                    v[3] = j;
                }
            }
        }
    }
    ans[v[0]][v[1]] = 1;
    ans[v[2]][v[3]] = 1;
    if(v[0] == v[2]){
        if(v[0] == n - 1){
            ans[v[0] -1][v[1]] = 1;
            ans[v[0] -1][v[3]] = 1;
        }
        else{
            ans[v[0] + 1][v[1]] = 1;
            ans[v[0] + 1][v[3]] = 1;
        }
    }
    else if(v[1] == v[3]){
        if(v[1] == n - 1){
            ans[v[0]][v[1] - 1] = 1;
            ans[v[2]][v[1] - 1] = 1;
        }
        else{
            ans[v[0]][v[1] + 1] = 1;
            ans[v[2]][v[1] + 1] = 1;
        }
    }
    else{
        ans[v[0]][v[3]] = 1;
        ans[v[2]][v[1]] = 1;
    }
    
    for(int i =0; i < n; ++i){
        for(int j =0; j < n; ++j){
            if(ans[i][j] == 0){
                printf(".");
            }
            else{
                printf("*");
            }
        }
        printf("\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



