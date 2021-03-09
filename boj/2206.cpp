#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

struct dd{
    int x, y, cou, wall;
};

int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};

int main(void){
    int row, col; scanf("%d%d", &row, &col);
    vector <vector <int> > v(row, vector <int> (col));
    for(int i =0; i < row; ++i){
        for(int j =0; j < col; ++j){
            scanf("%1d", &v[i][j]);
        }
    }
    queue <struct dd> que;
    int root[1000][1000][2];
    for(int i =0; i < row; ++i){
        for(int j =0; j < col; ++j){
            root[i][j][0] =0;
            root[i][j][1] =0;
            if(v[i][j] == 1){
                root[i][j][0] = 2;
                root[i][j][1] = 2;
            }
        }
    }
    root[0][0][0] = 1;
    root[0][0][1] = 1;
    que.push({0,0,1,0});
    while(!que.empty()){
        struct dd d = que.front();
        que.pop();
        if(d.x == row - 1 && d.y == col - 1){
            printf("%d", d.cou);
            return 0;
        }
        for(int i =0; i < 4; ++i){
            int nx = d.x + dir[i][0];
            int ny = d.y + dir[i][1];
            if(nx >= 0 && nx < row && ny >= 0 && ny < col){
                if(root[nx][ny][d.wall] == 0){
                    root[nx][ny][d.wall] = 1;
                    que.push({nx, ny, d.cou + 1, d.wall});
                }
                if(root[nx][ny][d.wall] == 2 && d.wall == 0){
                    que.push({nx, ny, d.cou + 1, 1});
                }
            }
        }
    }
    printf("%d", -1);
}
