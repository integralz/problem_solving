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

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> v(m + 1, -1);
    vector <int> ans = {0};
    for(int i =0; i < n; ++i){
        int a, c;
        ll b;
        scanf("%d%lld%d", &a, &b, &c);
        int an = (int)ans.size();
        for(int j =0; j < an; ++j){
            ll que = ans[j];
            for(int k =0; k < c; ++k){
                if(a == 1){
                    que *= 100000;
                    que += b + 99999;
                    que /= 100000;
                    if(que > m) break;
                    else if(v[que] != -1) break;
                    else{
                        v[que] = i + 1;
                        ans.push_back((int)que);
                    }
                }
                else{
                    que *= b;
                    que += 99999;
                    que /= 100000;
                    if(que > m) break;
                    else if(v[que] != -1) break;
                    else{
                        v[que] = i + 1;
                        ans.push_back((int)que);
                    }
                }
            }
        }
    }
    for(int i = 1; i <= m; ++i){
        printf("%d ", v[i]);
    }
    printf("\n");
}

int main(void){
    solve();
}


