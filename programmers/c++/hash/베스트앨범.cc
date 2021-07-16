#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map <string, int> mp;
vector <pair <int, int> > v[100];
pair <int,int> mat[100];
bool gg(pair <int, int> a, pair <int, int> b){
    return a.second > b.second;
}
bool dd(pair <int, int> a, pair <int, int> b){
    return a.second > b.second;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int que = 1;
    for(int i = 0; i < 100; ++i){
        mat[i] = {i,0};
    }
    for(int i = 0; i < genres.size(); ++i){
        if(mp[genres[i]] == 0){
            mp[genres[i]] = que;
            ++que;
        }
        v[mp[genres[i]]].push_back({i, plays[i]});
        mat[mp[genres[i]]].second += plays[i];
    }
    sort(mat, mat + 100, gg);
    for(int i = 1; i < que; ++i){
        sort(v[i].begin(), v[i].end(), dd);
    }
    for(int i = 0; i < que - 1; ++i){
       if((int)v[mat[i].first].size() < 2){
           answer.push_back(v[mat[i].first][0].first);
       }
        else{
            answer.push_back(v[mat[i].first][0].first);
            answer.push_back(v[mat[i].first][1].first);
        }
    }
    
    return answer;
}