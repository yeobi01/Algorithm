#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    
    stack<char> stk;
    stk.push(number[0]);
    
    for(int i = 1; i < number.length(); i++){
        if(k == 0){
            stk.push(number[i]);
            continue;
        }
        
        // cout << i << " " << k << " " << stk.top() << endl;
        while(!stk.empty() && stk.top() < number[i]){
            stk.pop();
            k--;
            if(k == 0) break;
        }
        stk.push(number[i]);
    }
    while(k--){
        stk.pop();
    }
    
    string reverse = "";
    while(!stk.empty()){
        reverse += stk.top();
        stk.pop();
    }
    
    string answer = "";
    for(int i = reverse.length() - 1; i >= 0; i--){
        answer += reverse[i];
    }
    
    return answer;
}