#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int mat[11];

bool gg(int a, int b){
    return a > b;
}

int main(void){
    int n;
    scanf("%d", &n);
    map <char, int> mp;
    vector <string> v(n);
    int que = 1;
    for(int i =0; i < n; ++i){
        cin >> v[i];
    }
    for(int i =0; i < n; ++i){
        for(int j =0; j < (int)v[i].size(); ++j){
            if(mp[v[i][j]] == 0){
                mp[v[i][j]] = que;
                ++que;
            }
            int a = 1;
            for(int k = 0; k < (int)v[i].size() - j - 1; ++k){
                a *= 10;
            }
            mat[mp[v[i][j]]] += a;
        }
    }
    sort(mat, mat + 11, gg);
    que = 9;
    int ans = 0;
    for(int i =0; i < 10;++i){
        ans += que * mat[i];
        que--;
    }
    printf("%d", ans);
    
}
