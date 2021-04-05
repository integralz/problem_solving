#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
    vector <int> v(n);
    vector <int> ans(n+ 1, 0);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    for(int i = 1; i < n + 1; ++i){
        ans[i] = (ans[i - 1] + v[i - 1]) % m;
    }
    vector <int> que(m, 0);
    for(int i =0; i < n + 1; ++i){
        que[ans[i]]++;
    }
    long long answer = 0;
    for(int i =0 ; i < m; ++i){
        if(que[i] > 1){
            answer += (long long)que[i] * (que[i] - 1) / 2;
        }
    }
    printf("%lld", answer);
}
