#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> v(n);
    vector <int> root(m);
    vector <ll> che;
    vector <int> que;
    ll rot = 0;
    ll ma = -1;
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
        rot += v[i];
        if(rot > 0 && ma < rot){
            che.push_back(rot);
            que.push_back(i);
            ma = max(rot, (ll)ma);
        }
    }
    for(int i =0; i < m; ++i){
        scanf("%d", &root[i]);
    }
    
    for(int i = 0; i < m; ++i){
        if(rot <= 0){
            if(ma >= root[i]){
                int ans = lower_bound(che.begin(), che.end(), root[i]) - che.begin();
                printf("%d ", que[ans]);
            }
            else{
                printf("-1 ");
            }
        }
        else{
            if(ma >= root[i]){
                int ans = lower_bound(che.begin(), che.end(), root[i]) - che.begin();
                printf("%d ", que[ans]);
            }
            else{
                int got = root[i];
                got -= ma;
                got += rot - 1;
                got /= rot;
                root[i] -= rot * got;
                int ans = lower_bound(che.begin(), che.end(), root[i]) - che.begin();
                printf("%lld ", que[ans] + (long long)n * got);
                
            }
        }
    }
    printf("\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}

