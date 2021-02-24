#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    for(int i =0; i < a; ++i){
        for(int j =0; j < b; ++j){
            int n;
            scanf("%d", &n);
            if((i + j) % 2 == 0){
                printf("%d ", 720720);
            }
            else{
                int g = 1;
                for(int k = 0; k < 4; ++k){
                    g *= n;
                }
                printf("%d ", g + 720720);
            }
        }
        printf("\n");
    }
}
