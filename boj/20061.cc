#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main(void){
    vector <vector <int> > v(4, vector <int> (4));
    vector <vector <int> > g(6, vector <int> (4));
    vector <vector <int> > b(4, vector <int> (6));
    int n;
    scanf("%d", &n);
    int answer = 0;
    for(int qqq = 0; qqq < n; ++qqq){
        int t, x, y;
        scanf("%d%d%d", &t, &x, &y);
        
        if(t == 1){
            bool gg = 0;
            for(int i = 0; i < 6; ++i){
                if(b[x][i] == 1){
                    b[x][i - 1] = 1;
                    gg = 1;
                    break;
                }
            }
            if(!gg){
                b[x][5] = 1;
            }
            gg = 0;
            for(int i = 0; i < 6; ++i){
                if(g[i][y] == 1){
                    g[i - 1][y] = 1;
                    gg = 1;
                    break;
                }
            }
            if(!gg){
                g[5][y] = 1;
            }
        }
        else if(t == 2){
            bool gg = 0;
            for(int i = 0; i < 5; ++i){
                if(!(b[x][i] == 0 && b[x][i + 1] == 0)){
                    b[x][i - 1] = 1;
                    b[x][i] = 1;
                    gg = 1;
                    break;
                }
            }
            if(!gg){
                b[x][5] = 1;
                b[x][4] = 1;
            }
            gg = 0;
            for(int i = 0; i < 6; ++i){
                if(!(g[i][y] == 0 && g[i][y + 1] == 0)){
                    g[i - 1][y] = 1;
                    g[i - 1][y + 1] = 1;
                    gg = 1;
                    break;
                }
            }
            if(!gg){
                g[5][y] = 1;
                g[5][y + 1] = 1;
            }
        }
        else if(t == 3){
            bool gg = 0;
            for(int i = 0; i < 6; ++i){
                if(!(b[x][i] == 0 && b[x + 1][i] == 0)){
                    b[x][i - 1] = 1;
                    b[x + 1][i - 1] = 1;
                    gg = 1;
                    break;
                }
            }
            if(!gg){
                b[x][5] = 1;
                b[x + 1][5] = 1;
            }
            gg = 0;
            for(int i = 0; i < 5; ++i){
                if(!(g[i][y] == 0 && g[i + 1][y] == 0)){
                    g[i - 1][y] = 1;
                    g[i][y] = 1;
                    gg = 1;
                    break;
                }
            }
            if(!gg){
                g[5][y] = 1;
                g[4][y] = 1;
            }
        }
        
        for(int i = 5; i >= 0; --i){
            int cou = 0;
            
            for(int j = 0; j < 4; ++j){
                if(b[j][i] == 1){
                    ++cou;
                }
            }
            if(cou == 4){
                ++answer;
                vector <vector <int> > root(4, vector <int> (i));
                for(int k = 0; k < 4; ++k){
                    for(int z = 0; z < i; ++z){
                        root[k][z] = b[k][z];
                    }
                }
                for(int k = 0; k < 4; ++k){
                    for(int z = 1; z < i + 1; ++z){
                        b[k][z] = root[k][z - 1];
                    }
                }
                for(int k =0; k < 4; ++k){
                    b[k][0] = 0;
                }
                ++i;
            }
        }
        
        for(int i = 5; i >= 0; --i){
            int cou = 0;
            
            for(int j =0; j < 4; ++j){
                if(g[i][j] == 1){
                    ++cou;
                }
            }
            if(cou == 4){
                ++answer;
                vector <vector <int> > root(i, vector <int> (4));
                for(int k = 0; k < i; ++k){
                    for(int z = 0; z < 4; ++z){
                        root[k][z] = g[k][z];
                    }
                }
                for(int k = 1; k < i + 1; ++k){
                    for(int z = 0; z < 4; ++z){
                        g[k][z] = root[k - 1][z];
                    }
                }
                for(int k =0; k < 4; ++k){
                    g[0][k] = 0;
                }
                ++i;
            }
        }
        
        bool gg[2] = {0, 0};
        for(int qq = 0; qq < 2; ++qq){
            for(int j = 0; j < 4; ++j){
                if(b[j][qq] == 1){
                    gg[qq] = 1;
                }
            }
        }
        
        if(gg[0] == 1 && gg[1] == 1){
            vector <vector <int> > root(4, vector <int> (4));
            for(int i = 0; i < 4; ++i){
                for(int j =0; j < 4; ++j){
                    root[i][j] = b[i][j];
                }
            }
            for(int i = 2; i < 6; ++i){
                for(int j =0; j < 4; ++j){
                    b[j][i] = root[j][i - 2];
                }
            }
            
            for(int i = 0; i < 2; ++i){
                for(int j =0; j < 4; ++j){
                    b[j][i] = 0;
                }
            }
        }
        else if(gg[1] == 1){
            vector <vector <int> > root(4, vector <int> (5));
            for(int i = 0; i < 4; ++i){
                for(int j =0; j < 5; ++j){
                    root[i][j] = b[i][j];
                }
            }
            for(int i = 1; i < 6; ++i){
                for(int j =0; j < 4; ++j){
                    b[j][i] = root[j][i - 1];
                }
            }
            
            for(int i = 0; i < 2; ++i){
                for(int j =0; j < 4; ++j){
                    b[j][i] = 0;
                }
            }
        }
        for(int i =0; i < 2; ++i){
            gg[i] = 0;
        }
        for(int qq =0; qq < 2; ++qq){
            for(int i = 0; i < 4; ++i){
                if(g[qq][i] == 1){
                    gg[qq] = 1;
                }
            }
        }
        
        if(gg[0] == 1 && gg[1] == 1){
            vector <vector <int> > root(4, vector <int> (4));
            for(int i =0; i < 4; ++i){
                for(int j =0; j < 4; ++j){
                    root[i][j] = g[i][j];
                }
            }
            for(int i = 2; i < 6; ++i){
                for(int j =0; j < 4; ++j){
                    g[i][j] = root[i - 2][j];
                }
            }
            for(int i =0 ; i < 2; ++i){
                for(int j =0; j < 4; ++j){
                    g[i][j] = 0;
                }
            }
        }
        else if(gg[1] == 1){
            vector <vector <int> > root(5, vector <int> (4));
            for(int i =0; i < 5; ++i){
                for(int j =0; j < 4; ++j){
                    root[i][j] = g[i][j];
                }
            }
            for(int i =1; i < 6; ++i){
                for(int j = 0; j < 4; ++j){
                    g[i][j] = root[i - 1][j];
                }
            }
            for(int i =0 ; i < 2; ++i){
                for(int j =0; j < 4; ++j){
                    g[i][j] = 0;
                }
            }
        }
        
    }
    
    int ans = 0;
    
    for(int i =0; i < 6; ++i){
        for(int j =0; j < 4; ++j){
            if(b[j][i] == 1){
                ++ans;
            }
            if(g[i][j] == 1){
                ++ans;
            }
        }
    }
    
    printf("%d\n%d",answer, ans);
    
}
