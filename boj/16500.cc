#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int ch(int st, vector <string> &v, string s, vector <int> & ans){
    if(ans[st] != -1){
        return ans[st];
    }
    int got = 0;
    for(int i =0; i < (int)v.size(); ++i){
        int a = (int)v[i].size();
        if(a + st > (int)s.size()){
            continue;
        }
        else{
            string q = s.substr(st, a);
            if(q == v[i]){
                if(a + st == (int)s.size()){
                    got = 1;
                }
                else{
                    if(ch(st + a, v, s, ans)){
                        got = 1;
                    }
                }
            }
        }
        
    }
    return ans[st] = got;
}

int main(void){
    string s;
    int n;
    cin >> s;
    scanf("%d", &n);
    vector <string> v(n);
    vector <int> ans((int)s.size(), -1);
    for(int i =0; i < n; ++i){
        cin >> v[i];
    }
    ch(0, v, s, ans);
    
    printf("%d", ans[0]);
}
