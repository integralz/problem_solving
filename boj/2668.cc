#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int mat[101];
int root[101];
vector <int> v;
int ans = 0;

bool dfs(){
    int a;
    while(1){
        a = mat[v.back()];
        if(a == v.front()){
            return true;
        }
        else{
            for(int i = 1; i < (int)v.size(); ++i){
                if(a == v[i]) return false;
            }
            v.push_back(a);
        }
    }
    
}


int main(void){
    int num;
    scanf("%d", &num);
    for(int i=1; i <= num; ++i){
        scanf("%d", &mat[i]);
        root[i] = 0;
    }
    
    for(int i = 1; i <= num; ++i){
        if(root[i] == 0){
            v.push_back(i);
            if(dfs()){
                for(int i =0 ; i < (int)v.size(); ++i){
                    root[v[i]] = 1;
                }
                while(!v.empty()){
                    v.pop_back();
                }
            }
            else{
                while(!v.empty()){
                    v.pop_back();
                }
            }
        }
    }
    for(int i = 1; i <= num; ++i){
        if(root[i] == 1) ++ans;
    }
    printf("%d\n", ans);
    for(int i = 1; i <= num; ++i){
        if(root[i] == 1) printf("%d\n", i);
    }
}
