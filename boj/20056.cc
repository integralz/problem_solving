#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

struct dd{
    int m, s, d;
};

int dir[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

int main(void){
    int n, m1, k;
    scanf("%d%d%d", &n, &m1, &k);
    vector <vector <vector <struct dd> > > v(n, vector <vector <struct dd > > (n));
    vector <vector <vector <struct dd> > > root(n, vector <vector <struct dd > > (n));
    
    for(int kk = 0; kk < k; ++kk){
        for(int i =0; i < n; ++i){
            for(int j =0; j < n; ++j){
                root[i][j].clear();
            }
        }
        if(kk == 0){
            for(int i = 0; i < m1; ++i){
                int x, y, m, s, d;
                scanf("%d%d%d%d%d", &x, &y, &m, &s, &d);
                --x;
                --y;
                v[x][y].push_back({m, s, d});
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                int x = i;
                int y = j;
                for(int z = 0; z < (int)v[i][j].size(); ++z){
                    int m = v[i][j][z].m;
                    int s = v[i][j][z].s;
                    int d = v[i][j][z].d;
                    int nx = ((x + dir[d][0] * s) % n + n) % n;
                    int ny = ((y + dir[d][1] * s) % n + n) % n;
                    root[nx][ny].push_back({m, s, d});
                }
            }
        }
        
        for(int i =0; i < n; ++i){
            for(int j =0; j < n; ++j){
                v[i][j].clear();
                if((int)root[i][j].size() >= 2){
                    int m = 0, s = 0;
                    int ss = root[i][j][0].d % 2;
                    bool kkkk = 1;
                    m += root[i][j][0].m;
                    s += root[i][j][0].s;
                    for(int z = 1; z < (int)root[i][j].size(); ++z){
                        m += root[i][j][z].m;
                        s += root[i][j][z].s;
                        if(root[i][j][z].d % 2 != ss){
                            kkkk = 0;
                        }
                    }
                    m /= 5;
                    s /= (int)root[i][j].size();
                    if(m == 0) continue;
                    else{
                        if(kkkk){
                            for(int z =0; z < 4; ++z){
                                v[i][j].push_back({m, s, 2 * z});
                            }
                        }
                        else{
                            for(int z =0; z < 4; ++z){
                                v[i][j].push_back({m, s, 2 * z + 1});
                            }
                        }
                    }
                }
                else{
                    for(int z = 0; z < (int)root[i][j].size(); ++z){
                        v[i][j].push_back({root[i][j][z].m, root[i][j][z].s, root[i][j][z].d});
                    }
                }
            }
        }
        
    }
    
    int ans = 0;
    for(int i =0; i < n; ++i){
        for(int j =0; j < n; ++j){
            for(int z = 0; z < (int)v[i][j].size(); ++z){
                ans += v[i][j][z].m;
            }
        }
    }
    printf("%d", ans);
    
}
