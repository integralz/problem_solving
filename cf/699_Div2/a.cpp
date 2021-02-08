#include <iostream>
#include <cstdio>
using namespace std;

int main(void){
    int num;
    int a, b;
    int left, right, top, bottom;
    string s;
    scanf("%d", &num);
    int ans1, ans2;
    
    for(int i = 0; i < num; ++i){
        scanf("%d%d", &a, &b);
        cin >> s;
        left = 0;
        right = 0;
        top = 0;
        bottom = 0;
        ans1 = -1;
        ans2 = -1;
        for(int i =0; i < (int)s.size(); ++i){
            if(s[i] == 'L'){
                ++left;
            }
            else if(s[i] == 'R'){
                ++right;
            }
            else if(s[i] == 'U'){
                ++top;
            }
            else{
                ++bottom;
            }
        }
        
        if(a >= 0){
            if(right >= a) ans1 = 1;
        }
        else{
            if(left >= -1*a) ans1 = 1;
        }
        if(b >= 0){
            if(top >= b) ans2 = 1;
        }
        else{
            if(bottom >= -1*b) ans2 = 1;
        }
        if(ans1 == 1 && ans2 == 1)
            printf("YES\n");
        else printf("NO\n");
    }

    
}
