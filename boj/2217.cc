#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool gg(int a, int b){
    return a > b;
}

int main(void){
    int n;
    int ans = -1;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    sort(v.begin(), v.end(), gg);
    for(int i =0; i < n; ++i){
        if(ans < (i + 1) * v[i]){
            ans = (i + 1) * v[i];
        }
    }
    printf("%d", ans);
    
}
