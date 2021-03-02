#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;
vector <int> v;

int mat[500001];

void solve(){
    int n;
    scanf("%d", &n);
    int a = upper_bound(v.begin(), v.end(), n - 1) - v.begin();
    
    int que;
    for(int i = a; i < (int)v.size(); ++i){
        if(mat[v[i] - n + 1] == 1){
            que = i;
            break;
        }
    }
    int k = v[que] - n + 1;
    int b = k * (n - 1);
    int c = upper_bound(v.begin(), v.end(), b) - v.begin();
    int ans;
    for(int i = c; i < (int)v.size(); ++i){
        if(mat[v[i] - b] == 1){
            ans = i;
            break;
        }
    }
    ans = v[ans] - b;
    for(int i =0; i < n; ++i){
        for(int j =0; j < n; ++j){
            if(i == n - 1 && j == n - 1){
                printf("%d ", ans);
            }
            else if(i == n - 1 || j == n - 1){
                printf("%d ", k);
            }
            else{
                printf("1 ");
            }
        }
        printf("\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    mat[1] = 1;
    for(int i = 2; i < 702; ++i){
        if(mat[i] == 1) continue;
        for(int j = 2* i; j < 500001; j += i){
            mat[j] = 1;
        }
    }
    for(int i = 2; i < 500001; ++i){
        if(mat[i] == 0) v.push_back(i);
    }
    
    while(n--){
        solve();
    }
}


