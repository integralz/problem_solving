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
    bool kk = 1;
    for(int i =0; i < n; ++i){
        if(s[i] != 'a'){
            kk = 0;
            break;
        }
    }
    if(kk){
        printf("NO\n");
    }
    else{
        string s1 = "a";
        s1 += s;
        bool kk = 1;
        for(int i =0; i <= n; ++i){
            if(s1[i] != s1[n - i]){
                kk = 0;
                break;
            }
        }
        if(!kk){
            printf("YES\n");
            cout << s1 << "\n";
            return;
        }
        s1 = "";
        s1 += s;
        s1 += "a";
        kk = 1;
        for(int i =0; i <= n; ++i){
            if(s1[i] != s1[n - i]){
                kk = 0;
                break;
            }
        }
        if(!kk){
            printf("YES\n");
            cout << s1 << "\n";
            return;
        }
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}




