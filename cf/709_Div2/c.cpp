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

bool gg(vector <pair <int, int> > a, vector <pair <int, int> > b){
    return (int)a.size() < (int)b.size();
}

bool bb(pair <int, int> a, pair <int, int> b){
    return a.first < b.first;
}

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> v(m);
    vector <vector <pair <int, int> > >q(n);
    vector <pair <int, int > > ans;
    vector <int> root(m, -1);
    for(int i =0; i < m; ++i){
        int a;
        scanf("%d", &a);
        v[i] = a;
        for(int j =0; j < a; ++j){
            int b;
            scanf("%d", &b);
            --b;
            q[b].push_back({i, b});
        }
    }
    sort(q.begin(), q.end(), gg);
    
    for(int i = 0; i < n; ++i){
        ans.clear();
        for(int j = 0; j < (int)q[i].size(); ++j){
            int a= q[i][j].first;
            v[a]--;
            ans.push_back({v[a], a});
        }
        sort(ans.begin(), ans.end(), bb);
        int cou = 0;
        for(int j =0; j < (int)ans.size(); ++j){
            int b = ans[j].second;
            if(root[b] == -1){
                root[b] = q[i][0].second;
                ++cou;
            }
            if(cou >= (m + 1) / 2){
                break;
            }
        }
    }
    bool kk = 1;
    for(int i =0; i < m; ++i){
        if(root[i] == -1){
            kk =0;
            break;
        }
    }
    if(!kk){
        printf("NO\n");
    }
    else{
        printf("YES\n");
        for(int i =0; i < m; ++i){
            printf("%d ", root[i] + 1);
        }
        printf("\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



