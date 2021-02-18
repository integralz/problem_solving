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
    int a;
    int que;
    int last;
    map <int, int> mp;
    scanf("%d", &a);
    mp[a]++;
    que = a;
    last = a;
    for(int i = 1; i < n; ++i){
        scanf("%d", &a);
        if(a != last){
            last = a;
            mp[a]++;
        }
    }
    map<int, int >::iterator iter;
        
        for(iter = mp.begin(); iter != mp.end() ; iter++){
            if(iter->first == que){
                mp[iter->first]--;
            }
            if(iter->first != last){
                mp[iter->first]++;
            }
        }
    int ans = 987654321;
    for(iter = mp.begin(); iter != mp.end() ; iter++){
        if(ans > iter->second){
            ans = iter->second;
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

