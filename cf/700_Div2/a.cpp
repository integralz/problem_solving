#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void solve(){
    string s;
    cin >> s;
    for(int i =0; i < s.size(); ++i){
        if(i % 2 == 0){
            if(s[i] == 'a'){
                s[i] = 'b';
            }
            else{
                s[i] = 'a';
            }
        }
        else{
            if(s[i] == 'z'){
                s[i] = 'y';
            }
            else{
                s[i] = 'z';
            }
        }
    }
    cout << s;
    cout <<"\n";
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


