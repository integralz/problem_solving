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
    string s3, s4;
    vector <int> s1, s2;
    scanf("%d", &n);
    cin >> s3 >> s4;
    int a = 0, b = 0;
    vector <int> v;
    for(int i =0; i < n; ++i){
        if(s3[i] == '0'){
            ++a;
        }
        else{
            ++b;
        }
        if(a == b){
            v.push_back(i);
        }
    }
    for(int i =0; i < n; ++i){
        s1.push_back(stoi(s3.substr(i, 1)));
        s2.push_back(stoi(s4.substr(i, 1)));
    }
    int que = n - 1;
    int back = 0;
    while(!v.empty()){
        int a = v.back();
        v.pop_back();
        bool kk = 1;
        for(int i = a + 1; i <= que; ++i){
            if((s1[i] + back) % 2 != s2[i]){
                kk =0;
                break;
            }
        }
        if(!kk){
            printf("NO\n");
            return;
        }
        if((s1[a] + back)% 2!= s2[a]){
            back += 1;
            back %= 2;
        }
        que = a;
    }
    
    bool kk = 1;
    for(int i =0; i <= que; ++i){
        if((s1[i] + back)%2 != s2[i]){
            kk =0;
            break;
        }
    }
    if(!kk){
        printf("NO\n");
    }
    else{
        printf("YES\n");
    }
    
    //printf("YES\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



