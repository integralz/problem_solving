#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <string>
using namespace std;
using ll = long long;

void solve(){
    int n, m;
    scanf("%d%d", &n, &m);
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    int cou =0;
    if(m == 1){
        cout << s << "\n";
    }
    else{
        char que = s[0];
        for(int i =0; i < n; ++i){
            if(que == s[i]) ++cou;
            else break;
        }
        if(cou < m){
            printf("%c\n", s[m - 1]);
        }
        else if(cou == m){
            if(cou == n){
                printf("%c\n", que);
            }
            else{
            char que1 = s[cou];
            int cou1 = 0;
            for(int i = cou; i < n; ++i){
                if(que1 == s[i]){
                    cou1++;
                }
                else break;
            }
            if(cou + cou1 == n){
                printf("%c", que);
                for(int i = 0; i < (cou1 + m - 1) / m; ++i){
                    printf("%c", que1);
                }
                printf("\n");
            }
            else{
                printf("%c", que);
                for(int i = cou; i < n; ++i){
                    printf("%c", s[i]);
                }
                printf("\n");
            }
            }
        }
        else{
            if(cou == n){
                for(int i =0; i < (n + m - 1)/m; ++i){
                    printf("%c", que);
                }
                printf("\n");
                
            }
            else{
                printf("%c", que);
                for(int i = m; i < n; ++i){
                    printf("%c", s[i]);
                }
                printf("\n");
            }
        }
    }
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


