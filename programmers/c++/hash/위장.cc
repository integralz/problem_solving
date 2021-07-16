#include <string>
#include <vector>
#include <map>
using namespace std;

map <string, int> mp;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(int i = 0; i < clothes.size(); ++i){
        mp[clothes[i][1]]++;
    }
    map <string, int> :: iterator it;
    for(it = mp.begin(); it != mp.end(); ++it){
        answer *= it->second + 1;
    }
    return answer - 1;
}