#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;


void change(vector <vector <int> > &v, int a, int b, int num){
    vector <vector <int> > root(num, vector <int > (num));
    for(int i = 0; i < num; ++i){
        for(int j = 0; j < num; ++j){
            root[i][j] = v[a + num - j - 1][b + i];
        }
    }
    for(int i = 0; i < num; ++i){
        for(int j =0; j < num; ++j){
            v[a + i][b + j] = root[i][j];
        }
    }
}

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main(void){
    int n, q;
    scanf("%d%d", &n, &q);
    int mat[7];
    mat[0] = 1;
    for(int i= 1; i < 7 ; ++i){
        mat[i] = 2 * mat[i - 1];
    }
    
    vector <vector <int> > v(mat[n], vector <int> (mat[n]));
    
    for(int i = 0; i <mat[n]; ++i){
        for(int j= 0; j < mat[n]; ++j){
            scanf("%d", &v[i][j]);
        }
    }
    
    for(int kkk = 0; kkk < q; ++kkk){
        int num;
        scanf("%d", &num);
        num = mat[num];
        
        int got = mat[n] / num;
        
        for(int i =0; i < got; ++i){
            for(int j =0; j < got; ++j){
                int a = i * num;
                int b = j * num;
                change(v, a, b, num);
            }
        }
        
        vector <pair <int, int> > root;
        for(int i =0; i < mat[n]; ++i){
            for(int j =0; j < mat[n]; ++j){
                int cou = 0;
                for(int qq = 0; qq < 4; ++qq){
                    int nx = i + dir[qq][0];
                    int ny = j + dir[qq][1];
                    if(nx >= 0 && nx < mat[n] && ny >= 0 && ny < mat[n] && v[nx][ny] > 0){
                        ++cou;
                    }
                }
                if(cou < 3 && v[i][j] > 0){
                    root.push_back({i, j});
                }
            }
        }
        
        for(int i =0; i < (int)root.size(); ++i){
            int x = root[i].first;
            int y = root[i].second;
            --v[x][y];
        }
        
        
    }
    
    int ans = 0;
    for(int i =0; i < mat[n]; ++i){
        for(int j =0; j < mat[n]; ++j){
            ans += v[i][j];
        }
        
    }
    printf("%d\n", ans);
    
    ans = 0;
    queue <pair <int, int > > que;
    vector <vector <int > > root1(mat[n], vector <int> (mat[n]));
    for(int i =0; i < mat[n]; ++i){
        for(int j =0; j < mat[n]; ++j){
            if(root1[i][j] == 0 && v[i][j] > 0){
                int co = 1;
                root1[i][j] = 1;
                que.push({i, j});
                while(!que.empty()){
                    int x= que.front().first;
                    int y = que.front().second;
                    que.pop();
                    for(int qq = 0; qq < 4; ++qq){
                        int nx = x + dir[qq][0];
                        int ny = y + dir[qq][1];
                        if(nx >= 0 && nx < mat[n] && ny >= 0 && ny < mat[n] && root1[nx][ny] == 0 && v[nx][ny] > 0){
                            root1[nx][ny] = 1;
                            que.push({nx, ny});
                            ++co;
                        }
                    }
                }
                ans = max(ans, co);
            }
        }
    }
    printf("%d", ans);
}
