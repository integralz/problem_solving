#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define long long ll;

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> mat(n);
    vector <int> v(3, 0);
    for(int i = 0; i < n; ++i){
        scanf("%d", &mat[i]);
        v[mat[i] % 3]++;
    }
    int que = n / 3;
    for(int i =0; i < 3; ++i){
        v[i] -= que;
    }
    int ans = 0;
    if(v[0] < 0){
        while(v[2] > 0){
            if(v[0] == 0){
                break;
            }
            v[2]--;
            v[0]++;
            ans += 1;
        }
        while(v[1] > 0){
            if(v[0] == 0){
                break;
            }
            v[1]--;
            v[0]++;
            ans += 2;
        }
    }
    if(v[1] < 0){
        while(v[0] > 0){
            if(v[1] == 0){
                break;
            }
            v[0]--;
            v[1]++;
            ans += 1;
        }
        while(v[2] > 0){
            if(v[1] == 0){
                break;
            }
            v[2]--;
            v[1]++;
            ans += 2;
        }
    }
    if(v[2] < 0){
        while(v[1] > 0){
            if(v[2] == 0){
                break;
            }
            v[1]--;
            v[2]++;
            ans += 1;
        }
        while(v[0] > 0){
            if(v[2] == 0){
                break;
            }
            v[0]--;
            v[2]++;
            ans += 2;
        }
    }
    printf("%d\n", ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


