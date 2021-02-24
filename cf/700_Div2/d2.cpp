#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(void){
    int n;
    scanf("%d", &n);
    vector <int> v;
    int que = -1;
    for(int i =0; i < n; ++i){
        int a;
        scanf("%d", &a);
        if(que == -1){
            que = a;
            v.push_back(a);
        }
        else{
            if(que != a){
                v.push_back(a);
                que = a;
            }
        }
    }
    vector <vector <int> > a(n + 1);
    map <int, int> mp;
    que = 1;
    for(int i =0; i < v.size(); ++i){
        int x = v[i];
        if(mp[x] == 0){
            mp[x] = que;
            a[que].push_back(i);
            ++que;
        }
        else{
            a[mp[x]].push_back(i);
        }
    }
    --que;
 
    int a1 = -1;
    int b1 = -1;
    int ans = 0;
    vector <int> che(que + 1, 0);
    for(int i =0; i < v.size(); ++i){
        if(a1 == -1){
            ++ans;
            a1 = v[i];
            che[mp[v[i]]]++;
        }
        else if(b1 == -1){
            ++ans;
            b1 = v[i];
            che[mp[v[i]]]++;
        }
        else if(a1 == v[i]){
            che[mp[v[i]]]++;
            continue;
        }
        else if(b1 == v[i]){
            che[mp[v[i]]]++;
            continue;
        }
        else{
            ++ans;
            if(che[mp[a1]] >= a[mp[a1]].size()){
                a1 = v[i];
            }
            else if(che[mp[b1]] >= a[mp[b1]].size()){
                b1 = v[i];
            }
            else{
                if(a[mp[a1]][che[mp[a1]]] > a[mp[b1]][che[mp[b1]]]){
                    a1 = v[i];
                }
                else{
                    b1 = v[i];
                }
            }
            che[mp[v[i]]]++;
        }
    }
    printf("%d", ans);
}



