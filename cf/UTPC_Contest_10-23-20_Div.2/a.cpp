#include <iostream>
#include <cstdio>
using namespace std;
 
bool mat[100001];
 
int main(void){
    int num, cou;
    int a;
    scanf("%d%d", &num, &cou);
    for(int i =0 ; i < cou; ++i){
        scanf("%d", &a);
        mat[a] = true;
    }
    for(int i = 1; i <= num; ++i){
        if(!mat[i]) printf("%d\n", i);
    }
}
