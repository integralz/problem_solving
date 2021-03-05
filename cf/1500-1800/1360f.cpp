#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector <string> v(n);
    string ans;
    for(int i=0; i < n; ++i){
        cin >> v[i];
    }
    ans = v[0];
    char save;
    for(int i =0; i < m; ++i){
        save = ans[i];
        for(char j = 'a'; j <= 'z'; ++j){
            bool kk = 1;
            ans[i] = j;
            for(int k = 0; k < n; ++k){
                int cou = 0;
                for(int z =0; z < m; ++z){
                    if(v[k][z] != ans[z])++cou;
                }
                if(cou > 1){
                    kk =0;
                    break;
                }
            }
            if(kk){
                cout << ans<<"\n";
                return;
            }
        }
        ans[i] = save;
    }
    printf("-1\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


