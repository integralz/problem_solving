#include <iostream>
#include <queue>
#include <vector>
#include <cstdio>
using namespace std;

int num, cou;
vector <int> v[32001];
priority_queue <int> que;
int mat[32001];

void top(){
    int x;
    for(int i = 1; i <= num; ++i){
        if(mat[i] == 0){
            que.push(-1*i);
        }
    }
    while(!que.empty()){
        x = que.top();
        que.pop();
        x *= -1;
        printf("%d ", x);
        for(int i = 0; i < v[x].size(); ++i){
            --mat[v[x][i]];
            if(mat[v[x][i]] == 0){
                que.push(-1*v[x][i]);
            }
        }
    }
}

int main(void){

    int a, b;
    scanf("%d%d", &num, &cou);
    for(int i = 0; i < cou; ++i){
        scanf("%d%d", &a, &b);
        v[a].push_back(b);
        mat[b]++;
    }
    
    top();

}