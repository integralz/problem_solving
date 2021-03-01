#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int cou;

void dfs(vector <int> &v, vector <int> &root, vector <int> &end, int i){
    root[i] = 1;
    int next = v[i];
    if(root[next] == 0){
        dfs(v, root, end, next);
    }
    else{
        if(end[next] == 0){
            for(int a = next; a != i; a = v[a]){
                ++cou;
            }
            ++cou;
        }
    }
    end[i] = 1;
}

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
        v[i]--;
    }
    vector <int> root(n, 0);
    vector <int> end(n, 0);
    
    for(int i =0; i < n; ++i){
        if(root[i] == 0){
            dfs(v, root, end, i);
        }
    }
    printf("%d\n", n - cou);
    
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        cou = 0;
        solve();
    }
}
