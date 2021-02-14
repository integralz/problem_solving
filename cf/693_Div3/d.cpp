#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool gg(int a, int b){
    return a > b;
}

void solve(){
    int n;
    int a;
    long long b = 0, c = 0;
    scanf("%d", &n);
    vector <int> v;
    for(int i = 0; i < n; ++i){
        scanf("%d", &a);
        v.push_back(a);
    }
    sort(v.begin(), v.end(), gg);
    
    for(int i = 0; i < n; ++i){
        if(i % 2 == 0){
            if(v[i] % 2 == 0){
                b += v[i];
            }
        }
        else{
            if(v[i] % 2 == 1){
                c += v[i];
            }
        }
    }
    if(b == c){
        printf("Tie\n");
    }
    else if(b >c){
        printf("Alice\n");
    }
    else{
        printf("Bob\n");
    }
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}
