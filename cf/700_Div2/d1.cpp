#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

void solve(){
    
}

int main(void){
    int n;
    scanf("%d", &n);
    vector <int> v1;
    vector <int> v2;
    vector <int> v(n);
    queue <pair <int, int> > ch;
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    
    int que = v[0];
    for(int i = 1; i < n; ++i){
        if(v[i] == que){
            for(int j = i; j < n; ++j){
                if(v[j] == que){
                    if(j == n - 1){
                        ch.push({i, que});
                    }
                }
                else{
                    ch.push({i, que});
                    que = v[j];
                    i = j;
                }
            }
        }
    }
    int a1 = -1;
    int a2 = -1;
    for(int i =0; i < n; ++i){
        if(a1 == v[i] && a2 == v[i]){
            continue;
        }
        else if(a1 == v[i]){
            v2.push_back(1);
            a2 = v[i];
        }
        else if(a2 == v[i]){
            v1.push_back(1);
            a1 = v[i];
        }
        else{
            while(!ch.empty()){
                if(ch.front().first <= i){
                    ch.pop();
                }
                else break;
            }
            if(!ch.empty()){
            if(ch.front().second == a1){
                v1.push_back(1);
                a1 = v[i];
            }
            else{
                v2.push_back(1);
                a2 = v[i];
            }
            }
            else{
                v1.push_back(1);
                a1 = v[i];
            }
        }
    }
    printf("%d", (int)v1.size() + (int)v2.size());
    
}


