#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<int, int> m;

int solution(vector<int> nums)
{
    for(int x : nums){
        m[x]++;
    }
    int n = nums.size();
    int answer = m.size() < n/2 ? m.size() : n/2;
    return answer;
}