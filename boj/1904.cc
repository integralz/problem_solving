#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    vector <int> v(n + 1, 0);
    v[0] = 1;
    v[1] = 1;
    for(int i = 2; i < n + 1; ++i){
        v[i] = v[i - 1] + v[i - 2];
        v[i] %= 15746;
    }
    printf("%d", v[n]);
}
