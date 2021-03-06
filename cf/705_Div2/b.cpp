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
    int a, b;
    scanf("%d%d", &a, &b);
    string s;
    cin >> s;
    int cou = (int)s.size();
    vector <int> v(26, 0);
    if(a % b != 0){
        printf("-1\n");
        return;
    }
    for(int i =0; i < cou; ++i){
        v[(int)s[i] - 97]++;
    }
    bool kk = true;
    for(int i =0; i < 26; ++i){
        if(v[i] % b != 0){
            kk = false;
            break;
        }
    }
    if(kk){
        cout << s << "\n";
        return;
    }
    else{
        for(int i = cou - 1; i >= 0; --i){
            v[(int)s[i] - 97]--;
            int get = cou - i;
            int re =0;
            int ma = -1;
            for(int j = 0; j < 26; ++j){
                if(v[j] % b ==0);
                else{
                    re += (b - (v[j] % b));
                    if(ma == -1 && j > (int)s[i] - 97){
                        ma = j;
                    }
                }
            }
           
            if(re > get || (get - re) % b != 0) continue;
            else{
                if((get - re) >= b){
                    if(s[i] != 'z'){
                    for(int j = 0; j < i; ++j){
                        printf("%c", s[j]);
                    }
                        
                    printf("%c", (int)s[i] + 1);
                    int g = (int)s[i]-96;
                        if(v[g] % b ==0){
                        for(int j =0; j < (get - re - b) / b; ++j){
                            for(int k = 0; k < b; ++k){
                                printf("%c", 'a');
                            }
                        }
                    for(int j =0; j < 26; ++j){
                        if(j == g){
                            for(int k =0; k < b - 1; ++k)
                            printf("%c", j + 97);
                        }
                        if(v[j] % b != 0){
                            int qq =(b - (v[j] % b));
                            for(int k = 0; k < qq; ++k){
                                printf("%c", j + 97);
                            }
                        }
                    }
                    
                    printf("\n");
                    return;
                        }
                        else{
                            for(int j =0; j < (get - re) / b; ++j){
                                for(int k = 0; k < b; ++k){
                                    printf("%c", 'a');
                                }
                            }
                            ++v[g];
                            for(int j =0; j < 26; ++j){
                                if(v[j] % b != 0){
                                    int qq =(b - (v[j] % b));
                                    for(int k = 0; k < qq; ++k){
                                        printf("%c", j + 97);
                                    }
                                }
                            }
                            
                            printf("\n");
                            return;
                        }
                    }
                }
                else{
                    if((int)s[i] - 97 >= ma) continue;
                    for(int j = 0; j < i; ++j){
                        printf("%c", s[j]);
                    }
                    
                    printf("%c", ma + 97);
                    v[ma]++;
                    
                    for(int j =0; j < 26; ++j){
                        if(v[j] % b != 0){
                            int qq =(b - (v[j] % b));
                            for(int k = 0; k < qq; ++k){
                                printf("%c", j + 97);
                            }
                        }
                    }
                    printf("\n");
                    return;
                }
            }
        }
    }
    printf("-1\n");
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}



