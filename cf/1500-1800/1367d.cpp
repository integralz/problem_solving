#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
using ll = long long;


bool gg(pair <int, int> a, pair <int, int> b){
    return a.first < b.first;
}

bool hh(pair <int, int> a, pair <int, int> b){
    return a.first > b.first;
}
void solve(){
    string s;
    int n;
    cin >> s;
    vector <pair <int, int> >  cou(26);
    for(int i =0; i < 26; ++i){
        cou[i].first = 0;
        cou[i].second = i;
    }
    for(int i =0; i < (int)s.size(); ++i){
        int a = s[i];
        a -= 97;
        cou[a].first++;
    }
    scanf("%d", &n);
    vector <int> v(n);
    for(int i =0; i < n; ++i){
        scanf("%d", &v[i]);
    }
    int que = 25;
    int co = 0;
    vector <int> root(n, 0);
    vector <int> ans;
    vector <int> q;
    string got = "";
    for(int i =0; i < n; ++i){
        got += "0";
    }
    while(1){
        q.clear();
        int a = 0;
        
        if(co == n){
            break;
        }
        for(int i =0; i < n; ++i){
            if(root[i] == 0){
                int che =0;
                for(int j = 0; j < (int)ans.size(); ++j){
                    che += abs(ans[j] - i);
                }
                if(che == v[i]){
                    root[i] = 1;
                    q.push_back(i);
                    ++a;
                }
            }
        }
        for(int i = que; i >= 0; --i){
            if(a <= cou[i].first){
                for(int j = 0; j < (int)q.size(); ++j){
                    got[q[j]] = (char)(cou[i].second + 97);
                }
                que = i - 1;
                break;
            }
        }
        co += a;
        for(int i =0; i < (int)q.size(); ++i){
            ans.push_back(q[i]);
        }
    }
    cout << got << "\n";
    
}

int main(void){
    int n;
    scanf("%d", &n);
    while(n--){
        solve();
    }
}


