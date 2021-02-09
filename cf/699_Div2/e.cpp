#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int mat[500000];
int color[500001];
int color1[500001];
int root[500001];
vector <pair <int, int> > v;

int main(void){
    int num;
    scanf("%d", &num);
    for(int i =0; i <= num; ++i){
        v.push_back({-1,-1});
    }
    for(int i = 0; i < num; ++i){
        scanf("%d", &mat[i]);
        ++color[mat[i]];
        ++color1[mat[i]];
        if(v[mat[i]].first == -1) v[mat[i]].first = i;
        v[mat[i]].second = i;
    }
    root[num] = 0;
    for(int i = num - 1; i >= 0; --i){
        --color1[mat[i]];
        root[i] = root[i + 1];
        if(v[mat[i]].first == i){
            root[i] = max(root[i], root[v[mat[i]].second + 1] + color[mat[i]]);
        }
        else{
            root[i] = max(root[i], color[mat[i]] - color1[mat[i]]);
        }
    }
    printf("%d", num - root[0]);
}
