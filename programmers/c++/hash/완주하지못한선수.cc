#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> mp;

string solution(vector<string> participant, vector<string> completion)
{
    string answer = "";

    for (int i = 0; i < completion.size(); ++i)
    {
        mp[completion[i]]++;
        ;
    }
    for (int i = 0; i < participant.size(); ++i)
    {
        if (mp[participant[i]] == 0)
        {
            answer += participant[i];
            return answer;
        }
        mp[participant[i]]--;
    }
}