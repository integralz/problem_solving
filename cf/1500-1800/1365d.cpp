#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;
int dir[4][2] = {{0,1}, {1,0}, {-1,0}, {0,-1}};
void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector <vector <char> > v(n, vector <char> (m));
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            scanf("%c", &v[i][j]);
            if(v[i][j] == '\n'){
                scanf("%c", &v[i][j]);
            }
        }
    }
    int cou =0;
    for(int i =0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(v[i][j] == 'G') ++cou;
            if(v[i][j] == 'B'){
                for(int k = 0; k < 4; ++k){
                    int nx = i + dir[k][0];
                    int ny = j + dir[k][1];
                    if(nx >= 0 && nx < n && ny >= 0 && ny < m){
                        if(v[nx][ny] == 'G'){
                            printf("NO\n");
                            return;
                        }
                        if(v[nx][ny] == '.'){
                            v[nx][ny] = '#';
                        }
                    }
                }
            }
        }
    }
    if(v[n - 1][m - 1] == '#'){
        if(cou == 0){
            printf("YES\n");
            return;
        }
        else{
            printf("NO\n");
            return;
        }
    }
    queue <pair <int, int> > que;
    que.push({n - 1, m - 1});
    vector <vector <int> > root(n, vector <int> (m));
    for(int i =0; i < n; ++i){
        for(int j =0; j < m; ++j){
            root[i][j] = 0;
        }
    }
    root[n - 1][m - 1] = 1;
    int co=0;
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i =0; i < 4; ++i){
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if(nx >= 0 && nx < n && ny >=0 && ny < m && root[nx][ny] == 0){
                if(v[nx][ny] == '.' || v[nx][ny] == 'G'){
                    root[nx][ny] = 1;
                    que.push({nx, ny});
                    if(v[nx][ny] == 'G') ++co;
                }
            }
        }
    }
   
    if(co == cou){
        printf("YES\n");
    }
    else printf("NO\n");
    

    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


