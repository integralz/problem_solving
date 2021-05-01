#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int row, col, num;
int mat[50][50];
int root1[50][50];
int r1,c1,s1;
vector <int> so;
vector <pair <pair <int, int>, int> > v;
int root[6];
int su, max1 = 987654321;

void dfs(){
    int ch, cou;
    int r,c,s;
    for(int i = 0; i < row; ++i)
    for(int j = 0; j < col; ++j)
        mat[i][j] = root1[i][j];
    for(int kk = 0; kk < num; ++kk){
        r = v[so[kk]].first.first;
        c = v[so[kk]].first.second;
        s = v[so[kk]].second;
    for(int i =1; i <= s; ++i){
        cou = 2*i;
        ch = mat[r-i][c-i];
        for(int j = 0; j < cou; ++j){
            mat[r -i+j][c - i] = mat[r - i + j + 1][c - i];
        } 
        for(int j = 0; j < cou; ++j){
            mat[r + i][c - i + j] = mat[r + i][c - i + j + 1];
        }
        for(int j = 0; j < cou; ++j){
            mat[r + i - j][c + i] = mat[r + i - j - 1][c + i];
        }
        for(int j = 0; j < cou -  1; ++j){
            mat[r - i][c +i - j] = mat[r - i][c + i -j - 1];
        }
        mat[r - i][c - i + 1] = ch;
    }
    }
  for(int i = 0; i < row; ++i){
        su = 0;
        for(int j = 0; j < col; ++j){
            su += mat[i][j];
        }
        if(su < max1) max1 = su;
    }
}

void bfs(int co){
    if(co == num){
        dfs();
    }
    else{
        for(int i = 0; i < num; ++i){
            if(root[i] == 0){
                so.push_back(i);
                root[i] = 1;
                bfs(co + 1);
                root[i]=0;
                so.pop_back();
            }
        }
    }
}

int main(void){
    scanf("%d%d%d", &row, &col, &num);
    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            scanf("%d", &root1[i][j]);

    for(int  i =0; i < num; ++i){
        scanf("%d%d%d", &r1, &c1, &s1);
        v.push_back(make_pair(make_pair(r1 -1,c1 - 1), s1));
    }

    bfs(0);

    printf("%d", max1);

    return 0;
}