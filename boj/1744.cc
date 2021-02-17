#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool gg(int a, int b){
    return a > b;
}

int main(void){
    int n;
    scanf("%d", &n);
    vector <int> plus;
    vector <int> minus;
    for(int i =0; i < n; ++i){
        int a;
        scanf("%d", &a);
        if(a > 0){
            plus.push_back(a);
        }
        else{
            minus.push_back(a);
        }
    }
    sort(minus.begin(), minus.end());
    sort(plus.begin(), plus.end(), gg);
    int ans = 0;
    for(int i =0; i < plus.size(); ++i){
        if(plus[i] == 1){
            ans += 1;
        }
        else{
            if(i == (int)plus.size() - 1){
                ans += plus[i];
            }
            else{
                if(plus[i + 1] != 1){
                    ans += plus[i] * plus[i + 1];
                    ++i;
                }
                else{
                    ans += plus[i];
                }
            }
        }
    }
    for(int i =0; i < minus.size(); ++i){
        if(i == (int)minus.size() - 1){
            ans += minus[i];
        }
        else{
            ans += minus[i] * minus[i + 1];
            ++i;
        }
    }
    printf("%d", ans);
}
