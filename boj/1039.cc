#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>
using namespace std;

int main(void){
    int n, m;
    scanf("%d%d", &n, &m);
    string s = to_string(n);
    int siz = (int)s.size();
    queue <string> que;
    que.push(s);
    for(int i =0; i < m; ++i){
        map <string, int> mp;
        if(que.empty()){
            printf("-1");
            return 0;
        }
        else{
            int a= (int)que.size();
            for(int j =0; j < a; ++j){
                string s1 = que.front();
                que.pop();
                for(int k =0; k < siz; ++k){
                    for(int z = k + 1; z < siz; ++z){
                        string s2 = s1;
                        char gg = s2[k];
                        s2[k] = s2[z];
                        s2[z] = gg;
                        if(s2[0] != '0' && mp[s2] == 0){
                            mp[s2] = 1;
                            que.push(s2);
                        }
                    }
                }
            }
        }
    }
    string ans = "0";
    while(!que.empty()){
        string s1 = que.front();
        que.pop();
        ans = max(s1, ans);
    }
    if(ans[0] == '0'){
        printf("-1");
        return 0;
    }
    cout << ans;
}
