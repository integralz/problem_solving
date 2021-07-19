#include <string>
#include <vector>
using namespace std;
int co;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for(int i = 0; i < prices.size(); ++i){
        co = 0;
        for(int j = i + 1; j < prices.size(); ++j){
            if(prices[i] > prices[j]){
                answer.push_back(j - i);
                break;
            }
            ++co;
        }
        if(co == prices.size() - i - 1) answer.push_back(prices.size() - i -1);
    }
    return answer;
}