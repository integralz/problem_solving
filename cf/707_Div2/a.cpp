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
    int n;
    scanf("%d", &n);
    vector <pair <int, int> > v(n);
    vector <int> tim(n);
    for(int i =0; i < n; ++i){
        scanf("%d%d", &v[i].first, &v[i].second);
    }
    for(int i =0; i < n; ++i){
        scanf("%d", &tim[i]);
    }
    tim[0] += v[0].first;
    for(int i = 1; i < n; ++i){
        tim[i] += v[i].first - v[i - 1].second;
    }
    int que = tim[0];
    for(int i =0; i < n - 1; ++i){
        que = max(que + (v[i].second - v[i].first + 1) / 2, v[i].second);
        que += tim[i + 1];
    }
    printf("%d\n", que);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


