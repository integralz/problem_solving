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

int gcd(int a, int b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    queue <pair <int, int> > que;
    vector <int> ans(n);
    vector <int> answer;
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    for(int i =0; i < n - 1; ++i){
        ans[i] = i + 1;
    }
    ans[n - 1] = 0;
    for(int i =0; i < n - 1; ++i){
        int a= gcd(v[i], v[i + 1]);
        if(a == 1){
            que.push({i, i + 1});
        }
    }
    if(gcd(v[n - 1], v[0]) == 1){
        que.push({n - 1, 0});
    }
    int qq = -1;
    while(!que.empty()){
        int a = que.front().first;
        int b = que.front().second;
        que.pop();
        if(qq != a){
            qq = b;
            ans[a] = ans[b];
            answer.push_back(b);
            if(gcd(v[a], v[ans[a]]) == 1){
                que.push({a, ans[a]});
            }
        }
    }
    printf("%d ", (int)answer.size());
    for(int i =0; i < (int)answer.size(); ++i){
        printf("%d ", answer[i] + 1);
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


