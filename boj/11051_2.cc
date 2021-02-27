#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int calc(int n, int k){
    int ans = 1;
    while(k != 0){
        if(k % 2 == 0){
            n *= n;
            n %= 10007;
            k /= 2;
        }
        else{
            ans *= n;
            ans %= 10007;
            k--;
        }
    }
    return ans;
}

int main(void){
    int n, k;
    scanf("%d%d", &n, &k);
    vector <int> v(n + 1);
    vector <int> cal(n + 1);
    v[0] = 1;
    cal[0] = 1;
    for(int i = 1; i < n + 1; ++i){
        v[i] = v[i - 1] * i % 10007;
    }
    for(int i = 1; i < n + 1; ++i){
        cal[i] = calc(v[i], 10005);
    }
    
    printf("%d", v[n] * cal[k] % 10007 * cal[n - k] % 10007);
}
