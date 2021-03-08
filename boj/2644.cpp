#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    vector <vector <int> > v(n);
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    int m;
    scanf("%d", &m);
    for(int i =0; i < m; ++i){
        int q, w;
        scanf("%d%d", &q, &w);
        --q;
        --w;
        v[q].push_back(w);
        v[w].push_back(q);
    }
    vector <int> root(n, 0);
    root[a] = 1;
    queue <pair <int, int> > que;
    que.push({a, 0});
    while(!que.empty()){
        int x = que.front().first;
        int y = que.front().second;
        que.pop();
        for(int i =0; i < v[x].size(); ++i){
            if(v[x][i] == b){
                printf("%d", y + 1);
                return 0;
            }
            if(root[v[x][i]] == 0){
                root[v[x][i]] = 1;
                que.push({v[x][i], y + 1});
            }
        }
    }
    printf("-1");
}
