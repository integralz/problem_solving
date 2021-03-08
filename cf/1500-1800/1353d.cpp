#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

struct gg{
bool operator()(pair <int, int> a, pair <int, int> b){
    if(a.second - a.first == b.second - b.first){
        return a.first > b.first;
    }
    else if(a.second - a.first < b.second - b.first){
        return true;
    }
    else{
        return false;
    }
}
};

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> ans(n, 0);
    int wh = 1;
    priority_queue <pair <int, int>, vector <pair <int, int> >, gg> que;
    que.push({0, n - 1});
    while(!que.empty()){
        int a = que.top().first;
        int b = que.top().second;
        que.pop();
        int mid = (a + b)/2;
        ans[mid] = wh;
        ++wh;
        if(mid + 1 <= b){
            que.push({mid + 1, b});
        }
        if(a <= mid - 1){
            que.push({a, mid - 1});
        }
    }
    for(int i =0; i < n; ++i){
        printf("%d ", ans[i]);
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


