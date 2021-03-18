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
int mat[3163];
vector <int> di;
void solve(){
    int n , k;
    scanf("%d%d", &n, &k);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
        for(int j =0; j < (int)di.size(); ++j){
            int a = di[j];
            while(v[i] % (a * a) == 0){
                v[i] /= (a*a);
            }
        }
    }
    int ans = 0;
    for(int i =0; i < n; ++i){
        map <int, int> mp;
        for(int j = i; j < n; ++j){
            int a= v[j];
            if(mp[a] != 0){
                ++ans;
                i = j - 1;
                break;
            }
            i = j;
            ++mp[a];
        }
    }
    ++ans;
    printf("%d\n", ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    for(int i = 2; i < 3163; ++i){
        if(mat[i] == 0){
            di.push_back(i);
            for(int j = 2*i; j < 3163; j += i){
                mat[j] = 1;
            }
        }
    }
    while(n--){
        solve();
    }
}



