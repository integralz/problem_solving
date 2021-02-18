#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    vector <int> ans(n, 0);
    vector <int> use(n, 0);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    ans[0] = v[0];
    use[0] = v[0];
    for(int i =1; i < n; ++i){
        use[i] = v[i];
        for(int j = i - 1; j >= 0; --j){
            if(v[i] > v[j]){
                use[i] = max(use[i],v[i] + use[j]);
            }
        }
        ans[i] = max(ans[i - 1], use[i]);
    }
    printf("%d", ans[n - 1]);
    
}
