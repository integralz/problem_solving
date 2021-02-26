#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int mat[64][64];
string s = "";

void che(int row, int col, int n){
    bool ch = true;
    int que = mat[row][col];
    for(int i = row; i < row + n; ++i){
        for(int j = col; j < col + n; ++j){
            if(que != mat[i][j]){
                ch = false;
                break;
            }
        }
        if(!ch) break;
    }
    if(ch){
        if(que == 1){
            s += "1";
        }
        else{
            s += "0";
        }
    }
    else{
        s += "(";
        for(int i =0 ; i < 2; ++i){
            for(int j =0 ; j < 2; ++j){
                che(row + i * (n/2), col + j * (n/2), (n/2));
            }
        }
        s += ")";
        
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    for(int i =0; i < n; ++i){
        for(int j =0 ; j < n; ++j){
            scanf("%1d", &mat[i][j]);
        }
    }
    che(0, 0, n);
    cout << s;
}

int main(void){
    solve();
}
