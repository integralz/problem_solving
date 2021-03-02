#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int cou;
int cou1;

void dfs(int a, vector <int> &v, vector <int> &root, vector <int> &end){
    root[a] = 1;
    int next = v[a];
    if(root[next] == 0){
        dfs(next, v, root, end);
    }
    else{
        if(end[next] == 0){
            for(int i = next; i != a; i = v[i]){
                ++cou;
            }
            ++cou;
        }
    }
    end[a] = 0;
}

void dfs1(int a, vector <vector <int> > &v, vector <int> &root){
    ++cou1;
    root[a] = 1;
    for(int i =0; i < (int)v[a].size(); ++i){
        int next = v[a][i];
        if(root[next] == 0){
            dfs1(next, v, root);
        }
    }
}


int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    vector <int> v(n);
    vector <int> root(n,0);
    vector <int> end(n,0);
    vector <int> root1(n, 0);
    vector <vector <int> > dir(n);
    vector <pair <int, int> > ans;
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
        v[i]--;
        dir[v[i]].push_back(i);
        if(i != v[i]){
            dir[i].push_back(v[i]);
        }
    }
    
    for(int i = 0; i < n; ++i){
        if(root1[i] == 0){
            cou = 0;
            cou1 = 0;
            dfs(i, v, root, end);
            dfs1(i, dir, root1);
            ans.push_back({cou, cou1});
        }
    }
    int siz = (int)ans.size();
    vector <vector <int> > dp(siz + 1);
    for(int i =0; i < siz + 1; ++i){
        dp[i].resize(k + 1, 0);
    }
    for(int i = 1; i <= siz; ++i){
        int a = ans[i - 1].first;
        int b = ans[i - 1].second;
        for(int j = 0; j < k + 1; ++j){
            int ma = 0;
            if(j - a >= 0 && j - b < 0){
                for(int k = 0; k <= j - a; ++k){
                    ma = max(ma, dp[i - 1][k] + j - k);
                }
                ma = max(ma, dp[i - 1][j]);
                dp[i][j] = ma;
            }
            else if(j - a >= 0 && j - b >= 0){
                for(int k = j - b; k <= j - a; ++k){
                    ma = max(ma, dp[i - 1][k] + j - k);
                }
                ma = max(ma, dp[i - 1][j]);
                dp[i][j] = ma;
            }
            else{
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    printf("%d", dp[siz][k]);
}
