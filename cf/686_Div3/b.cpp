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
    vector <pair <int, int> > v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i].first);
        v[i].second = i;
    }
    sort(v.begin(), v.end(), gg);
    
    for(int i =0; i < n; ++i){
        if(i < n - 1){
            if(v[i].first != v[i + 1].first){
                printf("%d\n", v[i].second + 1);
                return;
            }
            else{
                for(int j = i; j < n; ++j){
                    if(v[j].first != v[i].first){
                        i = j - 1;
                        break;
                    }
                    else{
                        i = j;
                    }
                }
            }
        }
        else{
            printf("%d\n", v[i].second + 1);
            return;
        }
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


