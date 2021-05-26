#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

vector <int > v(21, -1);


int fibo(int a){
    if(v[a] != -1) return v[a];
    return v[a] = fibo(a - 1) + fibo(a - 2);
}



int main(void){
    int a;
    scanf("%d", &a);
    
    v[0] = 0;
    v[1] = 1;
    v[2] = 1;
    printf("%d", fibo(a));
}
