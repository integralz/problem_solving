#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
using namespace std;

int dir[4][2] = {{0,1}, {1, 0}, {-1,0}, {0,-1}};

int main(void){
    map <int, int> mp;
    vector <vector <int> > v(3, vector <int> (3));
    
    for(int i =0; i < 3; ++i){
        for(int j =0; j < 3; ++j){
            scanf("%d", &v[i][j]);
        }
    }
    queue <pair <int,vector <vector <int> > > > que;
    que.push({0,{{1, 2, 3}, {4, 5, 6}, {7, 8, 0}}});
    mp[123456780] = 1;
    while(!que.empty()){
        int a = que.front().first;
        vector <vector <int> > v1 = que.front().second;
        int x, y;
        que.pop();
        bool k = 1;
        for(int i =0; i < 3; ++i){
            for(int j =0; j < 3; ++j){
                if(v1[i][j] != v[i][j]){
                    k = false;
                }
                if(v1[i][j] == 0){
                    x = i;
                    y = j;
                }
            }
        }
        if(k){
            printf("%d", a);
            return 0;
        }
        else{
            for(int i =0 ; i < 4; ++i){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                vector <vector <int> > ans(3, vector <int> (3));
                if(nx >= 0 && nx < 3 && ny >= 0 && ny < 3){
                    for(int i =0; i < 3; ++i){
                        for(int j =0; j < 3; ++j){
                            ans[i][j] = v1[i][j];
                        }
                    }
                    ans[x][y] = ans[nx][ny];
                    ans[nx][ny] = 0;
                    bool qq = 1;
                    int qqq = 0;
                    for(int i =0; i < 3; ++i){
                        for(int j =0; j < 3; ++j){
                            qqq *= 10;
                            qqq += ans[i][j];
                        }
                    }
                    if(mp[qqq] == 0){
                        mp[qqq] = 1;
                        que.push({a + 1,ans});
                    }
                }
            }
        }
        
    }
    printf("-1");
}
