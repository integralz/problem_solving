#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

bool gg(pair <int, int> a, pair <int, int> b){
    return a.first < b.first;
}
bool bb(pair <int, int> a, pair <int, int> b){
    return a.second < b.second;
}

void solve(){
    int n;
    scanf("%d", &n);
    vector <pair <int, int> > v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v.begin(), v.end(), gg);
    
    long long cou = 0;
    int que = 0;
    for(int i =0; i < n; ++i){
        cou += v[i].first;
        for(int j = i + 1; j < n; ++j){
            if(v[i].first == v[j].first){
                cou += v[j].first;
                i = j;
            }
            else{
                if(cou < (long long)v[j].first){
                    que = j;
                }
                break;
            }
        }
    }
    printf("%d\n", n - que);
    sort(v.begin() + que, v.end(), bb);
    for(int i = que; i < n; ++i){
        printf("%d ", v[i].second + 1);
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


