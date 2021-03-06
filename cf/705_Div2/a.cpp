#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    vector <int> v;
    int cou = 0;
    for(int i = b + 1; i <= a; ++i){
        v.push_back(i);
        ++cou;
    }
    for(int i = b - 1; i >= (b + 1) / 2; --i){
        v.push_back(i);
        ++cou;
    }
   
    printf("%d\n", cou);
    for(int i =0; i < (int)v.size(); ++i){
        printf("%d ", v[i]);
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


