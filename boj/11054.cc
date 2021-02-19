#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    vector <int> a(n, 0);
    vector <int> b(n, 0);
    
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    
    for(int i =0 ; i < n; ++i){
        for(int j = i - 1; j >= 0; --j){
            if(v[i] > v[j]){
                a[i] = max(a[i], 1 + a[j]);
            }
        }
    }
    for(int i = n- 1; i >= 0; --i){
        for(int j = i + 1; j < n; ++j){
            if(v[i] > v[j]){
                b[i] = max(b[i], 1 + b[j]);
            }
        }
    }
    
    int ans = 1;
    for(int i =0; i < n; ++i){
        ans = max(ans, 1 + a[i] + b[i]);
    }
    printf("%d", ans);
}
