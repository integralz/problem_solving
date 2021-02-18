#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int mat[1001][1001];

int main(void){
    string a, b;
    cin >> a;
    cin >> b;
    for(int i = 1; i <= a.size(); ++i){
        for(int j = 1; j <= b.size(); ++j){
            if(a[i - 1] == b[j - 1]){
                mat[i][j] = mat[i - 1][j - 1] + 1;
            }
            else{
                mat[i][j] = max(mat[i - 1][j], mat[i][j - 1]);
            }
        }
    }
    printf("%d", mat[(int)a.size()][(int)b.size()]);
}
