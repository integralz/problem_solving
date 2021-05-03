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

bool gg(pair <int, int> a, pair <int, int> b){
    return a.first > b.first;
}

void solve(){
    int n, m, x;
    scanf("%d%d%d", &n, &m, &x);
    vector <pair<int, int> > v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    priority_queue <pair <int, int> > pq;
    for(int i =1; i <= m; ++i){
        pq.push({0, i});
    }
    
    sort(v.begin(), v.end(), gg);
    vector <vector <int> > ans(m + 1);
    
    for(int i =0; i < n; ++i){
        int a = pq.top().first;
        int b = pq.top().second;
        pq.pop();
        a -= v[i].first;
        ans[b].push_back(v[i].second);
        pq.push({a, b});
    }
    
    int q1 = pq.top().first;
    vector <int> qq(n);
    for(int i =0; i < m - 1; ++i){
        pq.pop();
    }
    int q2 = pq.top().first;
    if(q1 - q2 <= x){
        printf("YES\n");
        for(int i = 1; i <= m; ++i){
            for(int j = 0; j < (int)ans[i].size(); ++j){
                int kk = ans[i][j];
                qq[kk] = i;
            }
        }
        for(int i =0; i < n; ++i){
            printf("%d ", qq[i]);
        }
        printf("\n");
        
    }
    else{
        printf("NO\n");
    }
    return;
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



