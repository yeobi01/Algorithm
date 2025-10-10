#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    
    sort(people.begin(), people.end());
    
    int answer = 0;
    int start = 0, end = people.size() - 1;
    while(start <= end){
        if(people[start] + people[end] <= limit){
            answer++;
            start++;
            end--;
        } else {
            answer++;
            end--;
        }
    }
    
    return answer;
}
