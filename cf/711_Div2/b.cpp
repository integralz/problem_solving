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

bool gg(int a, int b){
    return a > b;
}

void solve(){
    int n, w;
    scanf("%d%d", &n, &w);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    priority_queue <int> que;
    sort(v.begin(), v.end(), gg);
    for(int i =0; i < n; ++i){
        int a = v[i];
        if(que.empty()){
            que.push(w - a);
        }
        else{
            int b= que.top();
            que.pop();
            if(b >= a){
                que.push(b - a);
            }
            else{
                que.push(b);
                que.push(w - a);
            }
        }
    }
    printf("%d\n", (int)que.size());
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



