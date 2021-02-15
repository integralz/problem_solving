#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

bool gg(pair <int, int> a, pair <int, int> b){
    return a.second < b.second;
}

void solve(){
    int n1, n2;
    int a, b;
    vector <pair <int, int> > v;
    int que;
    int wh;
    
    scanf("%d%d", &n1,&n2);
    for(int i = 0; i < n2; ++i){
        scanf("%d%d", &a, &b);
        v.push_back({a,b});
    }
    
    sort(v.begin(), v.end(), gg);
    que = 0;
    for(int i = 0; i < n2; ++i){
        if(i == n2 - 1){
            if(que == 0){
                printf("NO\n");
                return;
            }
            else{
                if(que == v[i].first){
                    if((v[i].second - wh) % 2 == 1){
                        que = 0;
                    }
                    else{
                        printf("NO\n");
                        return;
                    }
                }
                else{
                    if((v[i].second - wh) % 2 == 0){
                        que = 0;
                    }
                    else{
                        printf("NO\n");
                        return;
                    }
                }
            }
        }
        else{
            if(que == 0){
                que = v[i].first;
                wh = v[i].second;
            }
            else{
                if(v[i].second == v[i + 1].second){
                    printf("NO\n");
                    return;
                }
                else{
                    if(v[i].first == que){
                        if((v[i].second - wh) % 2 == 1){
                            que = 0;
                        }
                        else{
                            printf("NO\n");
                            return;
                        }
                    }
                    else{
                        if((v[i].second - wh) % 2 == 0){
                            que = 0;
                        }
                        else{
                            printf("NO\n");
                            return;
                        }
                    }
                }
            }
        }
    }
    printf("YES\n");
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}
