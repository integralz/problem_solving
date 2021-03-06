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
    int a, b;
    scanf("%d%d", &a, &b);
    string s;
    cin >> s;
    vector <int> v(4);
    vector <int> v1(4);
    int n = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    for(int i = m; i < b; ++i){
        v[0] = n / 10;
        v[1] = n % 10;
        v[2] = i / 10;
        v[3] = i % 10;
        bool kk = 1;
        for(int k =0; k < 4; ++k){
            if(v[k] == 3 || v[k] == 4 || v[k] == 6 || v[k] == 7 || v[k] ==9){
                kk = false;
                break;
            }
        }
        if(kk){
            for(int k = 0; k < 4; ++k){
                if(v[3 - k] == 0){
                    v1[k] = 0;
                }
                else if(v[3 - k] == 1){
                    v1[k] = 1;
                }
                else if(v[3 - k] == 2){
                    v1[k] = 5;
                }
                else if(v[3 - k] == 5){
                    v1[k] = 2;
                }
                else if(v[3 - k] == 8){
                    v1[k] = 8;
                }
            }
            int q = v1[0] * 10 + v1[1];
            int w = v1[2] * 10 + v1[3];
            if(q < a && w < b){
                for(int k =0; k < 2; ++k){
                    printf("%d", v[k]);
                }
                printf(":");
                for(int k = 2; k < 4; ++k){
                    printf("%d", v[k]);
                }
                printf("\n");
                return;
            }
        }
    }
    for(int i = n + 1; i < a; ++i){
        for(int j =0; j < b; ++j){
            v[0] = i / 10;
            v[1] = i % 10;
            v[2] = j / 10;
            v[3] = j % 10;
            bool kk = 1;
            for(int k =0; k < 4; ++k){
                if(v[k] == 3 || v[k] == 4 || v[k] == 6 || v[k] == 7 || v[k] ==9){
                    kk = false;
                    break;
                }
            }
            if(kk){
                for(int k = 0; k < 4; ++k){
                    if(v[3 - k] == 0){
                        v1[k] = 0;
                    }
                    else if(v[3 - k] == 1){
                        v1[k] = 1;
                    }
                    else if(v[3 - k] == 2){
                        v1[k] = 5;
                    }
                    else if(v[3 - k] == 5){
                        v1[k] = 2;
                    }
                    else if(v[3 - k] == 8){
                        v1[k] = 8;
                    }
                }
                int q = v1[0] * 10 + v1[1];
                int w = v1[2] * 10 + v1[3];
                if(q < a && w < b){
                    for(int k =0; k < 2; ++k){
                        printf("%d", v[k]);
                    }
                    printf(":");
                    for(int k = 2; k < 4; ++k){
                        printf("%d", v[k]);
                    }
                    printf("\n");
                    return;
                }
            }
        }
    }
    printf("00:00\n");
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


