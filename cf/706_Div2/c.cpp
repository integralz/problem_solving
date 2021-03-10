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
    scanf("%d", &n);
    vector <int> v;
    vector <int> v1;
    for(int i =0; i < 2*n; ++i){
        int a, b;
        scanf("%d%d", &a, &b);
        if(a ==0){
            if(b < 0){
                b *= -1;
            }
            v.push_back(b);
        }
        else{
            if(a < 0){
                a *= -1;
            }
            v1.push_back(a);
        }
    }
    sort(v.begin(), v.end());
    sort(v1.begin(), v1.end());
    long double ans =0;
    for(int i =0; i < n; ++i){
        ans += sqrt((ll)v[i]*v[i] + (ll)v1[i] * v1[i]);
    }
    printf("%.9Lf\n", ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



