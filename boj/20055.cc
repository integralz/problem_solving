#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(void){
    int n,k;
    int des = 0;
    int cou = 0;
    scanf("%d%d", &n, &k);
    vector <int> v(2*n);
    vector <int> root(2*n, 0);
    vector <int> robot;
    for(int i = 0; i < 2 * n; ++i){
        scanf("%d", &v[i]);
    }
    while(des < k){
        ++cou;
        for(int i = 0; i < (int)robot.size(); ++i){
            if(robot[i] == n - 1){
                robot.erase(robot.begin() + i);
                root[n - 1] = 0;
                break;
            }
        }
        int x = v[2*n - 1];
        int y = root[2*n - 1];
        for(int i = 2 * n - 1; i > 0; --i){
            v[i] = v[i - 1];
            root[i] = root[i - 1];
        }
        v[0] = x;
        root[0] = y;
        
        for(int i =0; i < (int)robot.size(); ++i){
            robot[i] = (robot[i] + 1) % (2 * n);
        }
        
        for(int i = 0; i < (int)robot.size(); ++i){
            if(robot[i] == n - 1){
                robot.erase(robot.begin() + i);
                root[n - 1] = 0;
                break;
            }
        }
        
        for(int i =0; i < (int)robot.size(); ++i){
            int a = robot[i];
            int b = (a + 1) % (2 * n);
            if(root[b] == 0 && v[b] > 0){
                root[b] = 1;
                root[a] = 0;
                --v[b];
                robot[i] = b;
            }
        }
        if(root[0] == 0 && v[0] > 0){
            robot.push_back(0);
            root[0] = 1;
            v[0]--;
        }
        des = 0;
        for(int i =0; i < 2*n; ++i){
            if(v[i] <= 0) ++des;
        }
        
    }
    printf("%d", cou);
}
