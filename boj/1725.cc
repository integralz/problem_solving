#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

using ll = long long;

ll dc(int st, int end, vector <int> &v, int n){
    if(end < st){
        return -1;
    }
    if(st == end){
        return v[st];
    }
    int mid = (st + end)/2;
    ll ans = max(dc(st, mid - 1, v, n), dc(mid + 1, end, v, n));
    int l = mid;
    int r = mid;
    ll ans1 = (ll)v[mid];
    int min1 = v[mid];
    while(1){
        ans = max(ans, ans1);
        if(l == st && r == end){
            break;
        }
        else if(l == st){
            r++;
            min1 = min(min1, v[r]);
            ans1 = (ll)min1 * (r  - l + 1);
            
        }
        else if(r == end){
            l--;
            min1 = min(min1, v[l]);
            ans1 = (ll)min1*(r - l + 1);
        }
        else{
            if(v[l - 1] > v[r + 1]){
                l--;
                min1 = min(min1, v[l]);
                ans1 = (ll)min1*(r - l + 1);
            }
            else{
                r++;
                min1 = min(min1, v[r]);
                ans1 = (ll)min1 * (r  - l + 1);
            }
        }
    }
    return ans;
}


void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    ll ans = dc(0, n - 1, v, n);
    
    printf("%lld", ans);
}

int main(void){
    solve();
    
}
