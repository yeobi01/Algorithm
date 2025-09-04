#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<string, int> s;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    for(auto x : participant){
        s[x]++;
    }
    
    for(auto x : completion){
        s[x]--;
    }
    
    for(auto x : s){
        if(x.second) answer = x.first;
    }
    
    return answer;
}