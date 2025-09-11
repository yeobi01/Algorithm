#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> pq;
    for(auto x : scoville){
        pq.push(x);
    }
    
    int answer = 0;
    while(pq.top() < K){
        if(pq.size() == 1){
            answer = -1;
            break;
        }
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();
        int new_food_scoville = first + (2 * second);
        pq.push(new_food_scoville);
        answer++;    
    }
    
    return answer;
}