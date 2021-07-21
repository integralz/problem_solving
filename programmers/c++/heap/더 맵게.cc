#include <string>
#include <vector>
#include <queue>

using namespace std;
priority_queue <int> q;
int solution(vector<int> v, int K) {
    int answer = 0;
    int que;
    int a,b;
    
    for(int i = 0; i < v.size(); ++i)
        q.push(-1*v[i]);
    
    while(1){
         if(-1 *q.top() >= K) break;
        if(q.size() < 2){
            answer = -1;
            break;
        }
        a = -1 * q.top();
        q.pop();
        b = -1 * q.top();
        q.pop();
        que = a + 2*b;
        q.push(-1 * que);
        ++answer;
    }
  
    
    return answer;
}