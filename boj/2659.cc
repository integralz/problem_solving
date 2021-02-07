#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int mat[4];

int clock(int a){
    int got[4];
    int root[4];
    for(int i =0 ; i < 4; ++i){
        root[i] = 0;
    }
    for(int i =0 ; i < 4; ++i){
        got[3 - i] = a % 10;
        a /= 10;
        
    }
    for(int i =0; i < 4; ++i){
        for(int j = 0; j < 4; ++j){
            root[j] *= 10;
        }
        for(int j =0; j < 4; ++j){
            root[j] += got[(j + i) % 4];
        }
    }
    sort(root, root + 4);
    return root[0];
    
}

int main(void){
    int num = 0;
    int ans = 0;
    for(int i =0 ; i < 4; ++i){
        scanf("%d", &mat[i]);
    }
    for(int i = 0; i < 4; ++i){
        num *= 10;
        num += mat[i];
    }
    num = clock(num);
    for(int i = 1111; i <= num; ++i){
        if(clock(i) == i){
            ++ans;
        }
    }
    printf("%d", ans);
}
