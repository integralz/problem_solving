#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
using ll = long long;

ll make_max(int st, int end, vector <int> &v, int n){
    int mid = (st + end) / 2;
    if(end < st){
        return -1;
    }
    if(st == end){
        return (ll)v[st] * v[st];
    }
    ll ans = max(make_max(st, mid - 1, v, n), make_max(mid + 1, end, v, n));
    int a = mid;
    int b = mid;
    ll got = (ll)v[mid] * v[mid];
    int min1 = v[mid];
    ll k = v[mid];
    while(1){
        ans = max(ans, got);
        if(a == st && b == end){
            break;
        }
        else if(a == st){
            ++b;
            min1 = min(min1, v[b]);
            k += v[b];
            got = (ll)min1 * k;
        }
        else if(b == end){
            --a;
            min1 = min(min1, v[a]);
            k += v[a];
            got = (ll)min1 * k;
        }
        else{
            if(v[a - 1] > v[b + 1]){
                --a;
                min1 = min(min1, v[a]);
                k += v[a];
                got = (ll)min1 * k;
            }
            else{
                ++b;
                min1 = min(min1, v[b]);
                k += v[b];
                got = (ll)min1 * k;
            }
        }
    }
    return ans;
}

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    ll ans = make_max(0, n - 1, v, n);
    printf("%lld", ans);
}

int main(void){
    solve();
}
