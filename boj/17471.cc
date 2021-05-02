#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int num;
vector <int> mat[2];
vector <int> rou[10];
int root[10];
int po[10];
queue <int> q;
vector <int> v;
int a1,b1;
int ans = 987654321;

int che(int que){
    int x;
    q.push(mat[que][0]);
    v.push_back(mat[que][0]);
    for(int i = 0; i< num; ++i){
        root[i] = 0;
    }
    root[mat[que][0]] = 1;
    while(!q.empty()){
        x = q.front();
        q.pop();
        for(int i = 0; i < rou[x].size(); ++i){
            for(int j = 0; j < mat[que].size(); ++j){
                if(rou[x][i] == mat[que][j] && root[rou[x][i]] == 0){
                    q.push(rou[x][i]);
                    v.push_back(rou[x][i]);
                    root[rou[x][i]] = 1;
                    break;
                }
            }
        }
    }
    if(v.size() == mat[que].size()){
        while(!v.empty()) v.pop_back();
        return 1;
    }
    else{
        while(!v.empty()) v.pop_back();
        return 0;
    }
}

void dfs(int cou){
    if(cou == num){
        if(mat[0].size() == num) return;
        else {
            if(che(0));
            else return;
            if(che(1));
            else return;
            a1 = 0;
            b1 = 0;
            for(int i = 0; i < mat[0].size(); ++i){
                a1 += po[mat[0][i]];
            }
            for(int i = 0; i  < mat[1].size(); ++i){
                b1 += po[mat[1][i]];
            }
            if(b1 > a1){
                if(ans > b1 - a1) ans = b1-a1;
            }
            else{
                if(ans > a1 - b1) ans = a1 - b1;
            }
        }
    }
    else{
        for(int i = 0; i <2; ++i){
            mat[i].push_back(cou);
            dfs(cou + 1);
            mat[i].pop_back();
        }
    }
}

int main(void){
    int g, a;
    scanf("%d", &num);

    for(int i = 0; i < num; ++i){
        scanf("%d", &po[i]);
    }
    for(int i = 0; i < num; ++i){
        scanf("%d", &g);
        for(int j = 0; j < g; ++j){
            scanf("%d", &a);
            --a;
            rou[i].push_back(a);
        }
    }
    mat[0].push_back(0);
    dfs(1);

    if(ans == 987654321){
        printf("-1");
    }
    else{
        printf("%d", ans);
    }
}