#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool gg(pair <int, int> a, pair <int, int> b){
    return a.first < b.first;
}

int main(void){
    int n;
    scanf("%d", &n);
    vector <pair <int, int> > v(n);
    vector <int> root(n, 1);
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &v[i].first, &v[i].second);
    }
    sort(v.begin(), v.end(), gg);
    for(int i =0 ; i < n; ++i){
        for(int j = i - 1; j >= 0; --j){
            if(v[i].second > v[j].second){
                root[i] = max(root[i], root[j] + 1);
            }
        }
    }
    int ans = 0;
    
    for(int i = 0; i < n; ++i){
        ans = max(ans, root[i]);
    }
    
    printf("%d", n - ans);
    
    
}
