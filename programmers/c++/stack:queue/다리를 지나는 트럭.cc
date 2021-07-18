#include <string>
#include <vector>
using namespace std;

int st = 0;
int que = 0;
int wei = 0;
vector <int> v;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int tim;
    
    while(1){
        if(que == truck_weights.size()) break;
        
        if(wei + truck_weights[que] <= weight){
            wei += truck_weights[que];
            que++;
            v.push_back(0);
            for(int i = st; i < que; ++i)
                v[i]++;
            answer++;
            if(v[st] == bridge_length + 1){
                wei -= truck_weights[st];
                st++;
            }
        }
        else{
            tim = bridge_length - v[st];
            answer += tim;
            wei -= truck_weights[st];
            st++;
            for(int i = st; i < que; ++i)
                v[i] += tim;
        }
    }   
    answer += bridge_length;
    return answer;
}