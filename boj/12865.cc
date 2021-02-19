#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int mat[101][100001];
int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    vector <pair <int, int> > v(n + 1);
    
    for(int i =1; i <= n; ++i){
        scanf("%d%d", &v[i].first, &v[i].second);
    }
    for(int i = 1; i <= n; ++i){
        int a = 0;
        for(int j = 1; j <= k; ++j){
            mat[i][j] = mat[i - 1][j];
            if(j >= v[i].first){
                mat[i][j] = max(mat[i][j], mat[i - 1][j - v[i].first] + v[i].second);
            }
            if(a >= mat[i][j]){
                mat[i][j] = a;
            }
            else{
                a = max(mat[i][j], a);
            }
        }
    }
    
    printf("%d", mat[n][k]);
    
}
