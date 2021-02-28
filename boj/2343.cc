#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;


int main(void){
    int a, b;
    scanf("%d%d", &a, &b);
    vector <int> v(a);
    int a2 = 0;
    for(int i =0; i < a; ++i){
        scanf("%d", &v[i]);
        a2+= v[i];
    }
    int a1 = 1;
    int mid;
    int ans = a2;
    int que;
    int su;
    while(a1 <= a2){
        mid = (a1 + a2) /2;
        que = 1;
        su = 0;
        for(int i = 0; i < a; ++i){
            if(su + v[i] <= mid){
                su += v[i];
            }
            else{
                if(v[i] > mid) que = 987654321;
                que++;
                su = v[i];
            }
        }
        if(que <= b){
            ans = min(ans, mid);
            a2 = mid - 1;
        }
        else{
            a1 = mid + 1;
        }
    }
    printf("%d", ans);
    
}
