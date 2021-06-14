#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct dd{
    int x, y, cou, zcou;
};

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool gg(struct dd a, struct dd b){
    if(a.cou != b.cou){
        return a.cou > b.cou;
    }
    else{
        if(a.zcou != b.zcou){
            return a.zcou > b.zcou;
        }
        else{
            if(a.x != b.x){
                return a.x < b.x;
            }
            else{
                return a.y < b.y;
            }
        }
    }
}

int main(void){
    int n, num;
    scanf("%d", &n);
    num = n * n;
    vector <vector <int> > v(n, vector <int> (n));
    vector <vector <int> > ans(n, vector <int> (n));
    vector <vector <int> > qq(num, vector <int> (4));
    for(int pp = 0; pp < num; ++pp){
        int a;
        vector <int> b(4);
        vector <struct dd > v1;
        scanf("%d", &a);
        for(int i =0; i < 4; ++i){
            scanf("%d", &b[i]);
            qq[a - 1][i] = b[i];
        }
        
        for(int i =0; i < n; ++i){
            for(int j =0; j < n; ++j){
                int cou = 0;
                int zcou = 0;
                if(v[i][j] == 0){
                    for(int k =0; k < 4; ++k){
                        int nx = i + dir[k][0];
                        int ny = j + dir[k][1];
                        if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                            if(v[nx][ny] == 0){
                                ++zcou;
                            }
                            else{
                                for(int q = 0; q < 4; ++q){
                                    if(v[nx][ny] == b[q]){
                                        ++cou;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                    v1.push_back({i,j,cou,zcou});
                }
            }
        }
        sort(v1.begin(), v1.end(), gg);
        v[v1[0].x][v1[0].y] = a;
        ans[v1[0].x][v1[0].y] = v1[0].cou;
    }
    int answer = 0;
    for(int i =0 ; i < n; ++i){
        for(int j =0; j < n; ++j){
            int cou =0 ;
            int a = v[i][j] - 1;
            for(int k =0; k < 4; ++k){
                int nx = i + dir[k][0];
                int ny = j + dir[k][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n){
                    int b = v[nx][ny];
                    for(int q = 0; q < 4; ++q){
                        if(qq[a][q] == b){
                            ++cou;
                            break;
                        }
                    }
                }
            }
            if(cou == 1){
                answer += 1;
            }
            else if(cou == 2){
                answer += 10;
            }
            else if(cou == 3){
                answer += 100;
            }
            else if(cou == 4){
                answer += 1000;
            }
        }
    }
    printf("%d", answer);
}
