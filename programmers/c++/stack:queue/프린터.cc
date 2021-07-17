#include <string>
#include <vector>

using namespace std;

int que = 0;

int che(int q, vector <int> priorities){
    for(int i = q; i  < priorities.size(); ++i){
        if(priorities[q] < priorities[i]) return 1;
    }
    return 0;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    while(1){
        if(che(que, priorities)){
            priorities.push_back(priorities[que]);
            if(que == location) location = priorities.size() - 1;
            que++;
        }
        else{
            if(que == location) return answer + 1;
            else{
                answer++;
                que++;
            }
        }
    }
}