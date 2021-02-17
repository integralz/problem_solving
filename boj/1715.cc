#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int main(void){
    int n;
    long long ans =0;
    priority_queue <int> que;
    scanf("%d", &n);
    for(int i =0; i < n; ++i){
        int a;
        scanf("%d", &a);
        que.push(-1 * a);
    }
    for(int i =0; i < n - 1; ++i){
        int a = -1 * que.top();
        que.pop();
        int b = -1 * que.top();
        que.pop();
        ans += a + b;
        que.push(-1*(a + b));
    }
    printf("%lld", ans);
}
