#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int num;
int mat[51][51];
int score[51];
int root[51];
queue <pair <int, int> > que;

int dfs(){
    int cou = 1;
    int a, b = 0;
    for(int i = 1; i <= num; ++i){
        root[i] = 0;
    }
    root[que.front().first] = 1;
    while(!que.empty()){
        a = que.front().first;
        b = que.front().second;
        que.pop();
        for(int i = 1; i <= num; ++i){
            if(mat[a][i] == 1 && root[i] == 0){
                root[i] = 1;
                ++cou;
                que.push({i, b + 1});
            }
        }
    }
    if(cou == num){
        return b;
    }
    else return -1;
}

int main(void){
    int a, b;
    int ans = 987654321;
    int che = 0;
    scanf("%d", &num);
    while(1){
        scanf("%d%d", &a, &b);
        if(a == -1 && b == -1) break;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    for(int i = 1; i <= num; ++i){
        que.push({i, 0});
        score[i] = dfs();
    }
    for(int i = 1; i <= num; ++i){
        if(score[i] != -1){
            if(ans > score[i]) ans = score[i];
        }
    }
    
    for(int i = 1; i <= num; ++i){
        if(ans == score[i]) ++che;
    }
    printf("%d %d\n", ans, che);
    for(int i = 1; i <= num; ++i){
        if(ans == score[i]){
            printf("%d ", i);
        }
    }
}

