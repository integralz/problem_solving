#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    int b =0;
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
        b = max(v[i], b);
    }
    int ma = 0;
    scanf("%d", &ma);
    int ans =0;
    int a = 0;
    int mid;
    while(a <= b){
        int got =0;
        mid = (a + b) / 2;
        for(int i =0; i < n; ++i){
            if(mid <= v[i]){
                got += mid;
            }
            else{
                got += v[i];
            }
        }
        if(got <= ma){
            ans = max(ans, mid);
            a = mid + 1;
        }
        else{
            b = mid - 1;
        }
    }
    printf("%d", ans);
}
