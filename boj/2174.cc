#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct dd{
    int x, y, dir;
};

int row, col;
int n, m;
int ord, cou;
char how;
vector <dd> v;
int dir[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int mat[100][100];
int mov(){
    if(how == 'L'){
        cou %= 4;
        v[ord].dir += (4 - cou);
        v[ord].dir %= 4;
    }
    else if(how == 'R'){
        cou %= 4;
        v[ord].dir += cou;
        v[ord].dir %= 4;
    }
    else{
        mat[v[ord].x][v[ord].y] = 0;
        for(int i = 0; i <cou; ++i){
            v[ord].x += dir[v[ord].dir][0];
            v[ord].y += dir[v[ord].dir][1];
            if(v[ord].x < 0 || v[ord].x >= row || v[ord].y < 0 || v[ord].y >= col){
                printf("Robot %d crashes into the wall", ord + 1);
                return 1;
            }
            else if(mat[v[ord].x][v[ord].y] != 0){
                printf("Robot %d crashes into robot %d", ord + 1, mat[v[ord].x][v[ord].y]);
                return 1;
            }
        }
        mat[v[ord].x][v[ord].y] = ord + 1;
    }
    return 0;
}

int main(void){
    int x,y;
    char dir;
    struct dd g;
    scanf("%d%d%d%d", &col, &row, &n, &m);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d%c", &y, &x, &dir);
        scanf("%c", &dir);
        --x;
        g.x = row - x - 1;
        g.y = --y;
        if(dir == 'E') g.dir = 0;
        else if(dir == 'S') g.dir = 1;
        else if(dir == 'W') g.dir = 2;
        else g.dir = 3;
        v.push_back(g);
        mat[g.x][g.y] = i;
    }


    for(int i = 0; i < m; ++i){
        scanf("%d%c", &ord, &how);
        scanf("%c%d", &how, &cou);
        --ord;
        if(mov()) return 0;
    }
    printf("OK");
    
}