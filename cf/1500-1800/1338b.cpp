#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
using ll = long long;

void solve(){
    int n;
    scanf("%d", &n);
    vector <vector <int> > v(n + 1);
    for(int i =0; i < n - 1; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bool kk = true;
    bool qq = true;
    for(int i = 1; i <= n; ++i){
        if(!qq) break;
        int num = (int)v[i].size();
        if(num == 1){
            qq = false;
            queue <pair <int, int> > que;
            vector <int> root(n + 1, 0);
            que.push({i, 0});
            root[i] = 1;
            while(!que.empty()){
                int a = que.front().first;
                int b = que.front().second;
                que.pop();
                if(b % 2 == 1 && (int)v[a].size() == 1){
                    kk = false;
                    break;
                }
                for(int j =0; j < (int)v[a].size(); ++j){
                    int nx = v[a][j];
                    if(root[nx] == 0){
                        root[nx] = 1;
                        que.push({nx, b + 1});
                    }
                }
            }
        }
    }
     
    int cou =0;
    for(int i = 1; i <= n; ++i){
        if((int)v[i].size() == 1){
            ++cou;
        }
    }
    int cou1 =0;
    for(int i = 1; i <= n; ++i){
        bool gg = 1;
        for(int j =0; j < (int)v[i].size(); ++j){
            int a = v[i][j];
            if((int)v[a].size() == 1){
                gg = 0;
                break;
            }
        }
        if(!gg){
            ++cou1;
        }
    }
    if(kk) printf("%d ", 1);
    else printf("%d ", 3);
    printf("%d", n - cou + cou1 - 1);
}

int main(void){
    solve();
}

