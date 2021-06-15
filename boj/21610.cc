#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct dd{
    int x, y;
};

int che[4][2] = {{-1, -1}, {1, 1}, {-1, 1}, {1, -1}};
int dir[8][2] = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}};

int main(void){
    int row, num;
    scanf("%d%d", &row, &num);
    vector <vector <int> > mat(row, vector <int> (row));
    vector <vector <int> > root(row, vector <int> (row));
    vector <struct dd> v;
    vector <struct dd> ch;
    for(int i =0; i < row; ++i){
        for(int j =0; j < row; ++j){
            scanf("%d", &mat[i][j]);
        }
    }
    
    for(int kk =0; kk < num; ++kk){
        v.clear();
        ch.clear();
        if(kk == 0){
            for(int i =0; i < 2; ++i){
                for(int j =0; j < 2; ++j){
                    v.push_back({row - 1 - i, j});
                }
            }
        }
        else{
            for(int i =0; i < row; ++i){
                for(int j =0; j < row; ++j){
                    if(mat[i][j] >= 2 && root[i][j] == 0){
                        mat[i][j] -= 2;
                        v.push_back({i, j});
                    }
                    root[i][j] = 0;
                }
            }
        }
        int a,b;
        scanf("%d%d", &a, &b);
        --a;
        for(int i =0; i < (int)v.size(); ++i){
            int nx = (v[i].x + b*dir[a][0]) % row;
            int ny = (v[i].y + b*dir[a][1]) % row;
            if(nx < 0){
                nx += row;
            }
            if(ny < 0){
                ny += row;
            }
            ch.push_back({nx, ny});
            mat[nx][ny]++;
        }
        for(int qq =0; qq < (int)ch.size(); ++qq){
            int x = ch[qq].x;
            int y = ch[qq].y;
            root[x][y] = 1;
            int n = 0;
            for(int i =0; i < 4; ++i){
                int nx = x + che[i][0];
                int ny = y + che[i][1];
                if(nx >= 0 && nx < row && ny >= 0 && ny < row){
                    if(mat[nx][ny] > 0){
                        ++n;
                    }
                }
            }
            mat[x][y] += n;
        }

    }
    int ans = 0;
    for(int i =0; i < row; ++i){
        for(int j =0; j < row; ++j){
            if(mat[i][j] >= 2 && root[i][j] == 0){
                mat[i][j] -= 2;
            }
            ans += mat[i][j];
        }
    }
    printf("%d", ans);
}
