#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    vector <vector <int>> v(n);
    
    for(int i =0; i < n; ++i){
        for(int j =0 ; j < 3; ++j){
            int a;
            scanf("%d", &a);
            v[i].push_back(a);
        }
    }
    for(int i = 1; i < n; ++i){
        for(int j = 0; j < 3; ++j){
            if(j == 0){
                v[i][0] = min(v[i][0] + v[i - 1][1], v[i][0] + v[i - 1][2]);
            }
            else if(j ==1){
                v[i][1] = min(v[i][1] + v[i - 1][0], v[i][1] + v[i - 1][2]);
            }
            else{
                v[i][2] = min(v[i][2] + v[i - 1][1], v[i][2] + v[i - 1][0]);
            }
        }
    }
    int k = 987654321;
    for(int i =0; i < 3; ++i){
        if(v[n - 1][i] < k){
            k = v[n-1][i];
        }
    }
    printf("%d", k);
}
