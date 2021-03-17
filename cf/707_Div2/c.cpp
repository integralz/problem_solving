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
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i =0; i < 5000001; ++i){
        mat[i].first = -1;
        mat[i].second = -1;
    }
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    for(int i =0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            int a = v[i] + v[j];
            if(mat[a].first == -1){
                mat[a].first = i;
                mat[a].second = j;
            }
            else{
                if(mat[a].first != i && mat[a].second != j && mat[a].first != j && mat[a].second != i){
                    printf("YES\n");
                    printf("%d %d %d %d", mat[a].first + 1, mat[a].second + 1, i + 1, j + 1);
                    return;
                }
            }
        }
    }
    printf("NO\n");
}

int main(void){
    solve();
}


