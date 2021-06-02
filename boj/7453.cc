#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int num;
int mat1[4000], mat2[4000], mat3[4000], mat4[4000];
int root1[16000000], root2[16000000];
int main(void){
    int que =0;
    int a, b;
    int max;
    long long ans =0;
    long long que1, que2;
    scanf("%d", &num);
    for(int i = 0; i < num; ++i){
        scanf("%d%d%d%d", &mat1[i], &mat2[i], &mat3[i], &mat4[i]);
    }
    for(int i = 0; i < num; ++i){
        for(int j = 0; j < num; ++j){
            root1[que] = mat1[i] + mat2[j];
            root2[que] = mat3[i] + mat4[j];
            ++que;
        }
    }
    sort(root1, root1 + (num*num));
    sort(root2, root2 + (num * num));
    a = 0;
    b = num *num - 1;
    max = num *num;
  
    while(a < max && b >= 0){
        if(root1[a] + root2[b] == 0){
            que1= 0;
            que2 = 0;
            for(int i = a; i < max; ++i){
                if(root1[i] == root1[a])
                que1++;
                else break;
            }
            for(int i = b; i >= 0; --i){
                if(root2[i] == root2[b])
                ++que2;
                else break;
            }
            ans += que1 * que2;
           
            a += que1;
            b -= que2;
        }
        else if(root1[a] + root2[b] < 0){
            ++a;
        }
        else{
            --b;
        }
    }
    printf("%lld", ans);
}
