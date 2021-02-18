#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

//tree, mat, node, l, r
int min_seg(vector <int> &a, vector <int> &b, int node, int l, int r){
    if(l == r) return a[node] = b[l];
    int mid = (l + r) / 2;
    return a[node] = min(min_seg(a, b, 2*node, l, mid), min_seg(a, b, 2*node + 1, mid + 1, r));
}
//tree, start, end, node, findl, findr
int find_min_seg(vector <int> &v, int start, int end, int node, int l, int r){
    if(end < l || r < start){
        return 1987654321;
    }
    else if(l <= start && end <= r){
        return v[node];
    }
    int mid = (start + end) / 2;
    return min(find_min_seg(v, start, mid, 2*node, l, r), find_min_seg(v, mid + 1, end, 2*node + 1, l, r));
}

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    vector <int> mat(4*n);
    vector <int> c(n);
    for(int i =0;i < n; ++i){
        scanf("%d", &v[i]);
    }
    
    min_seg(mat, v, 1, 0, n - 1);
    c[n - 1] = v[n -1];
    for(int i = n - 2; i >= 0; --i){
        c[i] = max(v[i], c[i + 1]);
    }
    int a = v[0];
    for(int i =0; i < n - 2; ++i){
        a = max(a, v[i]);
        int l = i + 1;
        int r = n - 2;
        while(l <= r){
            int mid = (l + r) / 2;
            int a2 = find_min_seg(mat, 0, n - 1, 1, i + 1, mid);
            int a3 = c[mid + 1];
           
            if(a2 == a && a3 == a){
                printf("YES\n");
                printf("%d %d %d\n", i + 1, mid - i, n - mid - 1);
                return;
            }
            else if(a2 < a){
                r = mid - 1;
            }
            else if(a2 > a){
                l = mid + 1;
            }
            else if(a2 == a && a3 < a){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
    }
    printf("NO\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}

