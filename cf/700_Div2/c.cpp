#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

void solve(){
    
}

int main(void){
    int n;
    scanf("%d", &n);
    vector <int> v(n + 2);
    v[0] = 987654321;
    v[n + 1] = 987654321;
    int a = 1;
    int b = n;
    int mid;
    
    while(a <= b){
        mid = (a + b) / 2;
        for(int i = -1; i <= 1; ++i){
            if(mid + i != 0 && mid + i != n + 1){
                printf("? %d\n", mid + i);
                fflush(stdout);
                int q;
                scanf("%d", &q);
                v[mid + i] = q;
            }
            
        }
        if(v[mid] < v[mid - 1] && v[mid] < v[mid + 1]){
            printf("! %d\n", mid);
            fflush(stdout);
            return 0;
        }
        else if(v[mid] < v[mid - 1]){
            a = mid + 1;
        }
        else{
            b = mid - 1;
        }
    }
}


