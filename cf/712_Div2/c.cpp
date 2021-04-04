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
    string s;
    scanf("%d", &n);
    cin >> s;
    vector <int> v(n, 0);
    int cou = 0;
    for(int i =0; i < n; ++i){
        if(s[i] == '0'){
            ++cou;
        }
    }
    if(cou % 2 != 0){
        printf("NO\n");
        return;
    }
    cou = n - cou;
    cou /= 2;
    for(int i =0; i < n; ++i){
        if(s[i] == '1'){
            if(cou > 0){
                --cou;
                v[i] = 1;
            }
            else{
                v[i] = -1;
            }
        }
    }
    int kk = 0;
    int a= 0, b = 0;
    for(int i =0; i < n; ++i){
        if(v[i] == 0){
            if(kk == 0){
                a += 1;
                b -= 1;
                kk = 1;
            }
            else{
                a -= 1;
                b += 1;
                kk = 0;
            }
        }
        else{
            a += v[i];
            b += v[i];
        }
        if(a < 0 || b < 0){
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    kk = 0;
    for(int i =0; i < n; ++i){
        if(v[i] == 0){
            if(kk == 0){
                kk = 1;
                printf("(");
            }
            else{
                kk = 0;
                printf(")");
            }
        }
        else if(v[i] == 1){
            printf("(");
        }
        else{
            printf(")");
        }
    }
    printf("\n");
    kk = 1;
    for(int i =0; i < n; ++i){
        if(v[i] == 0){
            if(kk == 0){
                kk = 1;
                printf("(");
            }
            else{
                kk = 0;
                printf(")");
            }
        }
        else if(v[i] == 1){
            printf("(");
        }
        else{
            printf(")");
        }
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



