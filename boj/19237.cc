#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct dd{
    int x, y, dir;
    bool dead = 1;
    int data[4][4];
};

int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main(void){
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    vector <vector <pair <int, int > > > v(n, vector <pair <int, int > > (n));
    vector <struct dd > sh(m);
    
    for(int i =0; i < n; ++i){
        for(int j =0; j < n; ++j){
            v[i][j].first = -1;
            v[i][j].second = 0;
        }
    }
    
    
    for(int i =0; i < n; ++i){
        for(int j =0; j < n; ++j){
            int a;
            scanf("%d", &a);
            if(a != 0){
                sh[a - 1].x = i;
                sh[a - 1].y = j;
            }
        }
    }
    
    for(int i =0; i < m; ++i){
        int a;
        scanf("%d", &a);
        --a;
        sh[i].dir = a;
    }
    
    for(int i =0; i < m; ++i){
        for(int j =0; j < 4; ++j){
            for(int z= 0; z < 4; ++z){
                int a;
                scanf("%d", &a);
                --a;
                sh[i].data[j][z] = a;
            }
        }
    }
    //초기 냄새 뿌림
    for(int i =0; i < m; ++i){
        int x = sh[i].x;
        int y = sh[i].y;
        v[x][y].first = i;
        v[x][y].second = k;
    }
    
    
    for(int kkk = 0; kkk < 1000; ++kkk){
        //상어의 이동
        for(int i =0; i < m; ++i){
            if(!sh[i].dead) continue;
            int wh = sh[i].dir;
            bool qq = 0;
            for(int j =0; j < 4; ++j){
                int q = sh[i].data[wh][j];
                int nx = sh[i].x + dir[q][0];
                int ny = sh[i].y + dir[q][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                    if(v[nx][ny].first == -1){
                        qq = 1;
                        sh[i].x = nx;
                        sh[i].y = ny;
                        sh[i].dir = q;
                        break;
                    }
                }
            }
            if(!qq){
                for(int j = 0; j < 4; ++j){
                    int q = sh[i].data[wh][j];
                    int nx = sh[i].x + dir[q][0];
                    int ny = sh[i].y + dir[q][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                        if(v[nx][ny].first == i){
                            sh[i].x = nx;
                            sh[i].y = ny;
                            sh[i].dir = q;
                            break;
                        }
                    }
                }
            }
        }
        
        vector <vector <int> > mat(n, vector <int> (n));
        
        for(int i =0; i < m; ++i){
            if(!sh[i].dead) continue;
            int x = sh[i].x;
            int y = sh[i].y;
            if(mat[x][y] != 0){
                sh[i].dead = 0;
            }
            else{
                mat[x][y] = i + 1;
            }
        }
        
        for(int i =0; i < n; ++i){
            for(int j =0; j < n; ++j){
                if(v[i][j].first != -1){
                    v[i][j].second--;
                    if(v[i][j].second == 0){
                        v[i][j].first = -1;
                    }
                }
            }
        }
        
        for(int i =0; i < m; ++i){
            if(!sh[i].dead) continue;
            int x = sh[i].x;
            int y = sh[i].y;
            v[x][y].first = i;
            v[x][y].second = k;
        }
        
        int cou = 0;
        for(int i = 0; i < m; ++i){
            if(sh[i].dead){
                ++cou;
            }
        }
        if(cou == 1){
            printf("%d", kkk + 1);
            return 0;
        }
    }
    
    printf("-1");
    
    return 0;
}
