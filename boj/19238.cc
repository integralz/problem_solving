#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct dd{
    int x, y;
};

struct bb{
    int x, y, n;
};

bool gg(struct dd a, struct dd b){
    if(a.x != b.x){
        return a.x < b.x;
    }
    else{
        return a.y < b.y;
    }
}
int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

int main(void){
    int n, m, f;
    scanf("%d%d%d", &n, &m, &f);
    vector <vector <int> > v(n, vector <int> (n));
    vector <vector <vector <struct dd > > > data(n, vector <vector <struct dd> > (n, vector <struct dd> (0)));
    for(int i =0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &v[i][j]);
        }
    }
    struct dd car;
    scanf("%d%d", &car.x, &car.y);
    --car.x;
    --car.y;
    
    for(int i =0; i < m; ++i){
        int x, y, x1, y1;
        scanf("%d%d%d%d", &x, &y, &x1, &y1);
        --x;
        --y;
        --x1;
        --y1;
        data[x][y].push_back({x1, y1});
    }
    
    for(int qqq = 0; qqq < m; ++qqq){
        vector <vector <int> > root(n, vector <int> (n));
        vector <struct dd > ans;
        queue <struct bb> que;
        que.push({car.x, car.y, 0});
        
        int ma = 987654321;
        
        if((int)data[car.x][car.y].size() > 0){
            que.pop();
            ans.push_back({car.x, car.y});
            ma = 0;
        }
        
        root[car.x][car.y] = 1;
        
        while(!que.empty()){
            int x = que.front().x;
            int y = que.front().y;
            int num = que.front().n;
            if(ma <= num){
                break;
            }
            que.pop();
            for(int i =0; i < 4; ++i){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && root[nx][ny] == 0 && v[nx][ny] == 0){
                    root[nx][ny] = 1;
                    if((int)data[nx][ny].size() >= 1){
                        ma = min(ma, num + 1);
                        ans.push_back({nx, ny});
                    }
                    que.push({nx, ny, num + 1});
                }
            }
        }
        
        sort(ans.begin(), ans.end(), gg);
        if(ans.empty()){
            printf("-1");
            return 0;
        }
        int x1 = data[ans[0].x][ans[0].y].back().x;
        int y1 = data[ans[0].x][ans[0].y].back().y;
        data[ans[0].x][ans[0].y].pop_back();
        
        for(int i =0; i < n; ++i){
            for(int j =0; j < n; ++j){
                root[i][j] = 0;
            }
        }
        while(!que.empty()){
            que.pop();
        }
        
        que.push({ans[0].x, ans[0].y, 0});
        root[ans[0].x][ans[0].y] =1;
        int got = -1;
        while(!que.empty()){
            int x = que.front().x;
            int y = que.front().y;
            int num = que.front().n;
            que.pop();
            if(x == x1 && y == y1){
                got = num;
                break;
            }
            for(int i =0; i < 4; ++i){
                int nx = x + dir[i][0];
                int ny = y + dir[i][1];
                if(nx >= 0 && nx < n && ny >= 0 && ny < n && root[nx][ny] == 0 && v[nx][ny] == 0){
                    root[nx][ny] = 1;
                    que.push({nx, ny, num + 1});
                }
            }
        }
        
        if(got == -1){
            printf("-1");
            return 0;
        }
        else{
            ma += got;
            if(ma > f){
                printf("-1");
                return 0;
            }
            else{
                f -= ma;
                f += 2 * got;
                car.x = x1;
                car.y = y1;
            }
        }
    }
    printf("%d", f);
    
}
