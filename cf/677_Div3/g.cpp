#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

int mat[1000][1000];

void dy(int st, vector <vector <pair <int, int> > > v){
    priority_queue <pair <int, int> > que;
    mat[st][st] = 0;
    que.push({st, 0});
    while(!que.empty()){
        int a = que.top().first;
        int dist = -1 * que.top().second;
        que.pop();
        if(mat[st][a] < dist) continue;
        for(int i =0; i < v[a].size(); ++i){
            int b = v[a][i].first;
            int c = v[a][i].second + dist;
            if(c < mat[st][b]){
                mat[st][b] = c;
                que.push({b, -1 * c});
            }
            
        }
    }
}


int main(void){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    vector <vector <pair <int, int> > > v(a);
    vector <pair <int, int> > r;
    for(int i =0; i < b; ++i){
        int q,w,e;
        scanf("%d%d%d", &q, &w, &e);
        v[q - 1].push_back({w - 1, e});
        v[w - 1].push_back({q - 1, e});
    }
    for(int i =0; i < a; ++i){
        for(int j =0; j < a; ++j){
            mat[i][j] = 987654321;
        }
    }
    for(int i =0; i < a; ++i){
        dy(i, v);
    }
    for(int i =0; i < c; ++i){
        int q, w;
        scanf("%d%d", &q, &w);
        r.push_back({q - 1, w - 1});
    }
    long long ans = 987654321;
    
    for(int i = 0; i < a; ++i){
        for(int j = 0; j < v[i].size(); ++j){
            long long che = 0;
            int q1 = i;
            int q2 = v[i][j].first;
            for(int k = 0; k < c; ++k){
                int w1 = r[k].first;
                int w2 = r[k].second;
                int h = min(mat[w1][w2], mat[w1][q1] + mat[q2][w2]);
                h = min(h, mat[w1][q2] + mat[q1][w2]);
                che += h;
            }
            ans = min(che, ans);
        }
    }
    printf("%lld", ans);
    
}
