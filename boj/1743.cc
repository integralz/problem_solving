#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int mat[100][100];
int root[100][100];
queue <pair <int, int> > que;
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0, -1}};
int row, col, n;
int bfs(){
    int cou = 1;
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i =0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] == 1 && root[nx][ny] == 0){
                root[nx][ny] = 1;
                que.push({nx, ny});
                ++cou;
            }
        }
    }
    return cou;
}

int main(void){
    int ans = 0;
    scanf("%d%d%d", &row, &col, &n);
    for(int i =0; i < n; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        mat[a - 1][b - 1] = 1;
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(mat[i][j] == 1 && root[i][j] == 0){
                que.push({i,j});
                root[i][j] = 1;
                ans = max(bfs(), ans);
                
            }
        }
    }
    printf("%d", ans);
}
