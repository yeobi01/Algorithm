#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> prices) {
    int len = prices.size();
    vector<int> answer(len);
    
    stack<pair<int,int>> s;
    s.push({prices[0], 0});
    for (int i = 0; i < len; i++) {
        while (!s.empty() && s.top().first > prices[i]) {
            answer[s.top().second] = i - s.top().second;
            s.pop(); 
        }
        s.push({prices[i], i});
    }
    while(!s.empty()){
        pair<int,int> top = s.top();
        int top_value = top.first;
        int top_time = top.second;
        answer[top_time] = len - top_time - 1;
        s.pop();
    }
    
    return answer;
}
