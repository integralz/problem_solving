#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int row, col; 
int mat[10][10];
int co = 1;
int siz = 0;
queue <pair <int, int> > q;
vector <pair <int, int> > v[6];
vector <pair <pair <int, int>, int> > sc;
vector <pair <int, int> > f;
queue <int> q1;
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
int rou[6][6];
int ans = 987654321;
int root[6];
int good;

void che(){
    int c = 1, x;
    for(int i = 0; i < co; ++i)
        root[i] = 0;
    q1.push(0);
    root[0] = 1;
    while(!q1.empty()){
        x = q1.front();
        q1.pop();
        for(int i = 0; i < f.size(); ++i){
            if(f[i].first == x && root[f[i].second] == 0){
                root[f[i].second] = 1;
                q1.push(f[i].second);
                ++c;
            }
        }
    }
    if(c == co){
        if(ans > siz) ans = siz;
    }
}

void dfs(int cou){
    if(cou == sc.size()){
        che();
    }
    else{
        for(int i = 0; i < 2; ++i){
            if(i == 0){
                siz += sc[cou].second;
                f.push_back(make_pair(sc[cou].first.first, sc[cou].first.second));
                f.push_back(make_pair(sc[cou].first.second, sc[cou].first.first));
                dfs(cou + 1);
                f.pop_back();
                f.pop_back();
                siz -= sc[cou].second;
            }
            else{
                dfs(cou + 1);
            }
        }
    }
}

void ch(int x, int y){
    int ma = 987654321, c, kkk;
    for(int i = 0; i< v[x].size(); ++i){
        for(int j = 0; j < v[y].size(); ++j){
            c= 987654321;
            kkk = 1;
            if(v[x][i].first == v[y][j].first){
                if(v[y][j].second > v[x][i].second){
                    if(v[y][j].second - v[x][i].second > 2){
                        for(int k = v[x][i].second + 1; k < v[y][j].second; ++k){
                            if(mat[v[x][i].first][k] != 0){
                                 kkk = 0;
                                 break;
                                 }
                        }
                        if(kkk != 0)
                        c = v[y][j].second - v[x][i].second - 1;
                    }
                }
                else{
                    if(v[x][i].second - v[y][j].second > 2){
                        for(int k = v[y][j].second + 1; k < v[x][i].second; ++k)
                            if(mat[v[x][i].first][k] != 0) {
                                kkk = 0;
                                break;
                            }
                            if(kkk != 0)
                    c = v[x][i].second - v[y][j].second -1;
                    }
                }
            }
            else if(v[x][i].second == v[y][j].second){
                if(v[y][j].first > v[x][i].first){
                    if(v[y][j].first - v[x][i].first > 2){
                    for(int k = v[x][i].first + 1; k < v[y][j].first; ++k)
                    if(mat[k][v[x][i].second] != 0) {
                        kkk = 0;
                        break;
                    }   
                    if(kkk != 0)
                    c= v[y][j].first - v[x][i].first - 1;
                    }
                }
                else{
                    if(v[x][i].first - v[y][j].first > 2){
                    for(int k = v[y][j].first + 1; k < v[x][i].first; ++k)
                    if(mat[k][v[x][i].second] != 0){
                        kkk = 0; 
                        break;
                    }
                    if(kkk != 0)
                    c = v[x][i].first - v[y][j].first - 1;
                    }
                }
            }
            if(ma > c){
                ma = c;
            }
        }
    }
    if(ma == 987654321){
        rou[x][y] = 0;
        rou[y][x] = 0;
    }
    else{
        sc.push_back(make_pair(make_pair(x,y), ma));
        rou[x][y] = ma;
        rou[y][x] = ma;
    }
}

void bfs(int x1, int y1){
    int nx, ny, x, y;
    q.push(make_pair(x1, y1));
    mat[x1][y1] = co;
    v[co - 1].push_back(make_pair(x1, y1));
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; ++i){
            nx = x + dir[i][0];
            ny = y + dir[i][1];
            if(nx >= 0 && nx < row && ny >= 0 && ny < col && mat[nx][ny] == -1){
                mat[nx][ny] = co;
                q.push(make_pair(nx, ny));
                v[co - 1].push_back(make_pair(nx, ny));
            }
        }
    }
    ++co;
}

int main(void){
    scanf("%d%d", &row, &col);

    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            scanf("%d", &mat[i][j]);
            if(mat[i][j] == 1) mat[i][j] = -1;
        }
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(mat[i][j] == -1)
                bfs(i,j);
        }
    }
    --co;
    for(int i = 0; i < co; ++i){
        for(int j = i + 1; j < co; ++j){
            ch(i, j);
        }
    }
    good = sc.size();
    dfs(0);
    if(ans == 987654321) printf("-1");
    else
    printf("%d", ans);
}