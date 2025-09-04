#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> clothes_map;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    for(auto clothe : clothes){
        clothes_map[clothe[1]]++;
    }
    
    for(pair<string, int> x : clothes_map){
        // cout << x.second << "\n";
        answer *= (x.second + 1);
    }
    
    return answer - 1;
}