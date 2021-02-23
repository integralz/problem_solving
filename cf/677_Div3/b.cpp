#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    int que1 = 0;
    int que2 = 0;
    for(int i =0; i < n; ++i){
        if(v[i] == 1){
            que1 = i;
            break;
        }
    }
    for(int i = n - 1; i >= 0; --i){
        if(v[i] == 1){
            que2 = i;
            break;
        }
    }
    int ans = 0;
    for(int i = que1 + 1; i < que2; ++i){
        if(v[i] == 0){
            ++ans;
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


