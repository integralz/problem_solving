#include <iostream>
#include <cstdio>
using namespace std;

int mat[2][200001];
int su[200001];
int su1[200001];

int main(void){
    int num;
    int a,b,c;
    long long ans;
    scanf("%d", &num);
    while(num--){
        ans = 0;
        scanf("%d%d%d", &a, &b, &c);
        for(int i = 0; i < c; ++i){
            scanf("%d", &mat[0][i]);
            ++su[mat[0][i]];
        }
        for(int i =0; i < c; ++i){
            scanf("%d", &mat[1][i]);
            ++su1[mat[1][i]];
        }
        for(int i =0; i < c; ++i){
            ans += c + 1 - su[mat[0][i]] - su1[mat[1][i]];
        }
        printf("%lld\n", ans / 2);
        for(int i = 0; i <= a; ++i){
            su[i] = 0;
        }
        for(int i =0; i <= b; ++i){
            su1[i] = 0;
        }
    }
}
