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

int dfs(int a, vector <int>& mat, vector <int> &root, vector <vector <int> > &v){
    root[a] = 1;
    int ans = 0;
    for(int i =0; i < v[a].size(); ++i){
        int x = v[a][i];
        if(root[x] == 0){
            ans += dfs(x, mat, root, v);
        }
    }
    if(ans == 0){
        mat[a] = 0;
        return 1;
    }
    else{
        mat[a] = ans;
        return ans + 1;
    }
}
bool gg(int a, int b){
    return a > b;
}

void solve(){
    int n, got;
    scanf("%d%d", &n, &got);
    vector <vector <int> > v(n);
    vector <int> root(n, 0);
    vector <int> dep(n);
    vector <int> mat(n);
    for(int i =0;i< n - 1; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        --a;
        --b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    dfs(0, mat, root, v);
    for(int i =0; i < n; ++i){
        root[i] = 0;
    }
    queue <pair <int, int> > que;
    que.push({0, 0});
    root[0] = 1;
    while(!que.empty()){
        int x = que.front().first;
        int cou = que.front().second;
        que.pop();
        dep[x] = cou;
        for(int i =0; i < v[x].size(); ++i){
            int a = v[x][i];
            if(root[a] == 0){
                root[a] = 1;
                que.push({a, cou + 1});
            }
        }
    }
    for(int i =0; i < n; ++i){
        mat[i] -= dep[i];
    }
    sort(mat.begin(), mat.end(), gg);
    ll answer = 0;
    for(int i =0; i < n - got; ++i){
        answer += mat[i];
    }
    printf("%lld", answer);
}

int main(void){
    solve();
}


