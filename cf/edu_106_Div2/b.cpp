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
    string s;
    cin >> s;
    int n = (int)s.size();
    int que = 0;bool kk = 1;
    
    for(int i =0; i < n - 1; ++i){
        if(s[i] == '1' && s[i + 1] == '1'){
            que = 1;
        }
        if(s[i] == '0' && s[i + 1] == '0' && que == 1){
            kk = false;
            break;
        }
    }
    if(kk){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



