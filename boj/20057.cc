#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct dd{
    int x, y, dir;
};

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int sand[4][5][5] = {{{0, 0, 5, 0, 0},
    {0, 10, 0, 10, 0},
    {2, 7, 0, 7, 2},
    {0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0}},
    {{0, 0, 2, 0, 0},
        {0, 1, 7, 10, 0},
        {0, 0, 0, 0, 5},
        {0, 1, 7, 10, 0},
        {0, 0, 2, 0, 0}
    },
    {{0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0},
        {2, 7, 0, 7, 2},
        {0, 10, 0, 10, 0},
        {0, 0, 5, 0, 0}
    },
    {{0, 0, 2, 0, 0},
        {0, 10, 7, 1, 0},
        {5, 0, 0, 0, 0},
        {0, 10, 7, 1, 0},
        {0, 0, 2, 0, 0}
    }
};




int main(void){
    int n;
    scanf("%d", &n);
    vector <vector <int> > v(n + 4, vector <int> (n + 4));
    vector <struct dd > turn;
    
    for(int i = 2; i < n + 2; ++i){
        for(int j = 2; j < n + 2; ++j){
            scanf("%d", &v[i][j]);
        }
    }
    
    int x = n / 2 + 2;
    int y = n / 2 + 2;
    int que = 1;
    while(x != 2){
        for(int i =0; i < que; ++i){
            x += dir[3][0];
            y += dir[3][1];
            turn.push_back({x, y, 3});
            
        }
        for(int i =0; i < que; ++i){
            x += dir[2][0];
            y += dir[2][1];
            turn.push_back({x, y, 2});
        }
        ++que;
        for(int i = 0; i < que; ++i){
            x += dir[1][0];
            y += dir[1][1];
            turn.push_back({x, y, 1});
        }
        for(int i =0; i < que; ++i){
            x += dir[0][0];
            y += dir[0][1];
            turn.push_back({x, y, 0});
        }
        ++que;
    }
    --que;
    for(int i =0; i < que; ++i){
        x += dir[3][0];
        y += dir[3][1];
        turn.push_back({x, y, 3});
    }
    
    for(int qq =0; qq < (int)turn.size(); ++qq){
        x = turn[qq].x;
        y = turn[qq].y;
        int dir1 = turn[qq].dir;
        int su = v[x][y];
        int mi = 0;
        v[x][y] = 0;
        for(int i = -2; i <= 2; ++i){
            for(int j = -2; j <= 2; ++j){
                int nx = x + i;
                int ny = y + j;
                v[nx][ny] += sand[dir1][i + 2][j + 2] * su / 100;
                mi += sand[dir1][i + 2][j + 2] * su / 100;
            }
        }
        su -= mi;
        int nx = x + dir[dir1][0];
        int ny = y + dir[dir1][1];
        v[nx][ny] += su;
    }
    
    int ans = 0;
    for(int i =0; i < n + 4; ++i){
        for(int j =0; j < n + 4; ++j){
            ans += v[i][j];
        }
    }
    
    for(int i = 2; i < n + 2; ++i){
        for(int j = 2; j < n + 2; ++j){
            ans -= v[i][j];
        }
    }
    printf("%d", ans);
    
}
