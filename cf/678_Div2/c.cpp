#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;

int calc(int a, int b){
    int ans = 1;
    while(b != 0){
        if(b % 2 == 0){
            a = (ll)a * a % 1000000007;
            b /= 2;
        }
        else{
            ans = (ll)ans * a % 1000000007;
            b--;
        }
    }
    return ans;
}

int main(void){
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    int q1 = 0;
    int q2 = a;
    int q =0;
    int w = 0;
    int k = 0;
    
    while(q1 < q2){
        int mid = (q1 + q2) / 2;
        if(k == 1){
            q2 = mid;
            ++w;
        }
        else{
        if(mid == c){
            q1 = mid + 1;
            k = 1;
        }
        else{
            if(mid > c){
                ++w;
                q2 = mid;
            }
            else{
                ++q;
                q1 = mid + 1;
            }
        }
        }
    }
    int left = b - 1;
    int right = a - b;
    vector <int> mat(1001);
    vector <int> inv(1001);
    mat[0] = 1;
    inv[0] = 1;
    for(int i = 1; i < 1001; ++i){
        mat[i] = (ll)i * mat[i - 1] % 1000000007;
    }
    for(int i = 1; i < 1001; ++i){
        inv[i] = calc(mat[i], 1000000005);
    }
    int ans = 1;
    ans = (ll)mat[left] * inv[q] % 1000000007 * inv[left - q] % 1000000007 * mat[q] %1000000007;
    ans = (ll)ans * mat[right] % 1000000007 * inv[w] % 1000000007 * inv[right - w] % 1000000007 * mat[w] % 1000000007;
    ans = (ll)ans * mat[a - 1 - q - w] % 1000000007;
    
    if(left < q || right < w){
        printf("0");
    }
    else printf("%d", ans);
}


