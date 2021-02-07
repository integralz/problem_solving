#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int row;
int mat[25][25];
int root[25][25];
queue <pair <int, int> > que;
vector <int> v;
int dir[4][2] ={{1,0},{0,1},{-1,0},{0,-1}};
int cou;

void bfs(){
    int x, y, nx, ny;
    cou = 1;
    while(!que.empty()){
        x = que.front().first;
        y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; ++i){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(nx >= 0 && nx < row && ny >= 0 && ny < row && mat[nx][ny] == 1 && root[nx][ny] == 0){
                ++cou;
                root[nx][ny] = 1;
                que.push({nx, ny});
            }
        }
    }
    v.push_back(cou);
}

int main(void){
    scanf("%d", &row);
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < row; ++j){
            scanf("%1d", &mat[i][j]);
            root[i][j] = 0;
        }
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < row; ++j){
            if(mat[i][j] == 1 && root[i][j] == 0){
                root[i][j] = 1;
                que.push({i,j});
                bfs();
            }
        }
    }
    sort(v.begin(), v.end());
    printf("%d\n", (int)v.size());
    for(int i =0; i < v.size(); ++i){
        printf("%d\n", v[i]);
    }
}
