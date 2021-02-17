#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define long long ll;

bool gg(pair <int, int> a, pair <int, int> b){
    return a.first < b.first;
}

void solve(){
    int n;
    scanf("%d", &n);
    int ans = 1;
    vector <pair <int, int> > v(n);
    for(int i =0; i < n; ++i){
        scanf("%d%d", &v[i].first, &v[i].second);
    }
    sort(v.begin(), v.end(), gg);
    int que = v[0].second;
    for(int i =1; i < n; ++i){
        if(v[i].second < que){
            ++ans;
            que = v[i].second;
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

