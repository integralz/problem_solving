#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int row, col;
int mat[50][50];
int root[50][50];
int ma = 0;
vector <pair <int, int> > v;
queue <pair <int, int> > que;
int dir[4][2] ={{0,1}, {0,-1}, {1,0}, {-1,0}};
int ans = 0;

void bfs(int x1, int y1, int co){
    int x, y, nx, ny, ch = 1;
    que.push(make_pair(x1, y1));
    v.push_back(make_pair(x1, y1));
    root[x1][y1] = 1;
    while(!que.empty()){
        x = que.front().first;
        y = que.front().second;
        que.pop();
        for(int i = 0; i < 4; ++i){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && root[nx][ny] == 0 &&  mat[nx][ny] <= co){
                que.push(make_pair(nx, ny));
                v.push_back(make_pair(nx, ny));
                root[nx][ny] = 1;
            }
        }
    }
    for(int i = 0; i < v.size(); ++i){
        if(v[i].first == 0 || v[i].second == 0 || v[i].first == row - 1 || v[i].second == col - 1){
            ch = 0;
            break;
        }
    }
    if(ch == 0){
        while(!v.empty()) v.pop_back();
    }
    else{
        for(int i = 0; i < v.size(); ++i){
            ++ans;
            mat[v[i].first][v[i].second]++;
        }
        while(!v.empty()) v.pop_back();
    }
}

void dfs(int co){
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            root[i][j]=0;
        }
    }
    for(int i = 0; i< row; ++i){
        for(int j = 0; j < col; ++j){
            if(mat[i][j] == co && root[i][j] == 0){
                bfs(i,j, co);
            }
        }
    }
}

int main(void){
    scanf("%d%d", &row, &col);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            scanf("%1d", &mat[i][j]);
            if(mat[i][j] > ma) ma = mat[i][j];
        }
    }

    for(int i = 1; i < ma; ++i){
        dfs(i);
    }
    printf("%d", ans);
}