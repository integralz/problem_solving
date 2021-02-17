#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
#define long long ll;

void make(vector <int> &v, vector <int> &root, int left, int right, int a){
    int cou = -1;
    int que = -1;
    if(left > right) return;
    for(int i = left; i <= right; ++i){
        if(cou < v[i]){
            cou = v[i];
            que = i;
        }
    }
    root[que] = a;
    
    make(v, root, left, que - 1, a + 1);
    make(v, root, que + 1, right, a + 1);
}

void solve(){
    int n;
    scanf("%d", &n);
    vector <int> v(n);
    vector <int> root(n, -1);
    for(int i = 0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    int left = 0;
    int right = n - 1;
    make(v, root, left, right, 0);
    for(int i =0; i < n; ++i){
       printf("%d ", root[i]);
    }
    printf("\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


