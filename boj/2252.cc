#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

vector <int> mat[32000];
int root[32000];
int num, cou;
queue <int> q;
void top_sort(){
    int a;
    for(int i = 0; i < num; ++i){
        if(root[i] == 0) q.push(i);
    }
    for(int i = 0; i < num; ++i){
        if(q.empty()) return;
        else{
            a = q.front();
            q.pop();
            for(int i = 0; i < mat[a].size(); ++i){
                --root[mat[a][i]];
                if(root[mat[a][i]] == 0){
                    q.push(mat[a][i]);
                }
            }
            printf("%d ", a + 1);
        }
    }
}

int main(void){
    int a, b;
    scanf("%d%d", &num, &cou);
    for(int i = 0; i < cou; ++i){
        scanf("%d%d", &a, &b);
        --a;
        --b;
        mat[a].push_back(b);
        root[b]++;
    }

    top_sort();

    return 0;
}