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
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    vector <int> s;
    for(int i= 0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    for(int i = 1; i < v[0]; ++i){
        s.push_back(i);
    }
    for(int i = 0; i < n - 1; ++i){
        for(int j = v[i] + 1; j < v[i + 1]; ++j){
            s.push_back(j);
        }
    }
    for(int i = v[n - 1] + 1; i <= 2*n; ++i){
        s.push_back(i);
    }
    int ls = 0;
    int a = 1;
    int b = n;
    int mid;
    while(a <= b){
        mid = (a + b)/2;
        int q1 = mid - 1;
        int q2 = n - 1;
        bool che = true;
        for(int i =0; i < mid; ++i){
            if(v[q1] < s[q2]){
                --q1;
                --q2;
            }
            else{
                che = false;
                break;
            }
        }
        if(che){
            ls = max(ls, mid);
            a = mid + 1;
        }
        else{
            b = mid - 1;
        }
    }
    int rs = 0;
    a = 1;
    b = n;
    while(a <= b){
        mid = (a + b)/ 2;
        int q2 = 0;
        int q1 = n - mid;
        bool che = true;
        for(int i =0; i < mid; ++i){
            if(v[q1] > s[q2]){
                ++q1;
                ++q2;
            }
            else{
                che = false;
                break;
            }
        }
        if(che){
            rs = max(rs, mid);
            a = mid + 1;
        }
        else{
            b = mid - 1;
        }
    }
    rs = n - rs;
    printf("%d\n", ls - rs + 1);
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}

