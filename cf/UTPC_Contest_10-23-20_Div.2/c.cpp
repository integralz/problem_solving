#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

map <string, int> mp;
int mat[200];

int main(void){
    int num;
    int cou, get;
    string s;
    int a,b;
    int sum;
    int ans = 0;
    
    scanf("%d", &num);
    for(int i =0 ; i < num; ++i){
        cin >> s;
        scanf("%d", &a);
        mp[s] = a;
    }
    scanf("%d%d", &cou, &get);
    for(int i = 0; i < cou; ++i){
        scanf("%d", &a);
        sum = 0;
        for(int j = 0; j < a; ++j){
            cin >> s;
            scanf("%d", &b);
            sum += mp[s] * b;
        }
        mat[i] = sum;
    }
    sort(mat, mat + cou);
    
    for(int i = 0; i < get; ++i){
        ans += mat[cou - i - 1];
    }
    printf("%d", ans);
}
