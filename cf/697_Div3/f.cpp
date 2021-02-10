#include <iostream>
#include <cstdio>
using namespace std;

int a[1000][1000];
int b[1000][1000];
int c[1000][1000];

void solve(){
    int n;
    bool t;
    scanf("%d", &n);
    for(int i =0; i < n; ++i){
        for(int j =0; j < n; ++j){
            scanf("%1d", &a[i][j]);
            if(a[i][j] == 0) a[i][j] = -1;
            b[i][j] = a[i][j];
        }
    }
    for(int i =0; i < n; ++i){
        for(int j =0; j < n; ++j){
            scanf("%1d", &c[i][j]);
            if(c[i][j] == 0) c[i][j] = -1;
        }
    }
    for(int i = 0; i < n; ++i){
        a[0][i] *= -1;
        if(a[0][i] != c[0][i]){
            for(int j =0; j < n; ++j){
                a[j][i] *= -1;
            }
        }
    }
    for(int i = 1; i < n; ++i){
        if(a[i][0] != c[i][0]){
            for(int j = 0; j < n; ++j){
                a[i][j] *= -1;
            }
        }
    }
    
    t = true;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(a[i][j] != c[i][j]){
                t = false;
                break;
            }
            if(t == false) break;
        }
    }
    if(t){
        printf("YES\n");
        return;
    }
    for(int i = 0; i < n; ++i){
        if(b[0][i] != c[0][i]){
            for(int j = 0; j < n; ++j){
                b[j][i] *= -1;
            }
        }
    }
    
    for(int i = 1; i < n; ++i){
        if(b[i][0] != c[i][0]){
            for(int j = 0; j < n; ++j){
                b[i][j] *= -1;
            }
        }
    }
    t = true;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(b[i][j] != c[i][j]){
                t = false;
                break;
            }
            if(t == false) break;
        }
    }
    if(t){
        printf("YES\n");
        return;
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
