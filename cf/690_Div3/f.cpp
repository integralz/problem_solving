#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define long long ll;

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> st(n);
    vector <int> end(n);
    vector <pair <int, int> > v(n);
    for(int i =0; i < n; ++i){
        scanf("%d%d", &v[i].first, &v[i].second);
        st[i] = v[i].first;
        end[i] = v[i].second;
    }
    sort(st.begin(), st.end());
    sort(end.begin(), end.end());
    int ans = n - 1;
    for(int i =0; i < n; ++i){
        int left = (int)(lower_bound(end.begin(), end.end(), v[i].first) - end.begin());
        int right = max(0, n - (int)(upper_bound(st.begin(), st.end(), v[i].second) - st.begin()));
        ans = min(ans, left + right);
    }
    printf("%d\n", ans);
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


