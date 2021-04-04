
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
    int n;
    scanf("%d", &n);
    int num = n*n;
    int que;
    int que1;
    int got;
    queue <pair <int, int> > qq1, qq2;
    scanf("%d", &que);
    got = que;
    --que;
    que = (que + 1) % 3;
    que1 = (que + 1) % 3;
    ++que;
    ++que1;
    --num;
    cout << que << " " << 1 << " " << 1 << endl;
    cout.flush();
    
    int s1 = 0, s2 = 0;
    for(int i =0; i < n; ++i){
        for(int j =0; j < n; ++j){
            if((i + j) % 2 == 0){
                ++s1;
                qq1.push({i + 1, j + 1});
            }
            else{
                ++s2;
                qq2.push({i + 1, j + 1});
            }
        }
    }
    qq1.pop();
    --s1;
    while(num--){
        int a;
        scanf("%d", &a);
        if(s1 > 0 && s2 > 0){
            if(a == que){
                --s2;
                cout << que1 << " " << qq2.front().first << " " << qq2.front().second << endl;
                cout.flush();
                qq2.pop();
            }
            else{
                --s1;
                cout << que << " " << qq1.front().first << " " << qq1.front().second << endl;
                cout.flush();
                qq1.pop();
            }
        }
        else if(s1 > 0){
            --s1;
            if(a != got){
                cout << got << " " << qq1.front().first << " " << qq1.front().second << endl;
                cout.flush();
            }
            else{
                cout << que << " " << qq1.front().first << " " << qq1.front().second << endl;
                cout.flush();
            }
            qq1.pop();
        }
        else{
            --s2;
            if(a != got){
                cout << got << " " << qq2.front().first << " " << qq2.front().second << endl;
                cout.flush();
            }
            else{
                cout << que1 << " " << qq2.front().first << " " << qq2.front().second << endl;
                cout.flush();
            }
            qq2.pop();
        }
    }
}

int main(void){
    solve();
}

