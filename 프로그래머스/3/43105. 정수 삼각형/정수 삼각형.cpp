#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp;
    dp.push_back({triangle[0][0]});
    for(int i = 1; i < triangle.size(); i++){
        vector<int> temp(triangle[i].size());
        for(int j = 0; j < triangle[i].size(); j++){
            int prev1 = (j != 0) ? dp[i - 1][j - 1] : 0;
            int prev2 = (j < dp[i - 1].size()) ? dp[i - 1][j] : 0;
            
            temp[j] = prev1 > prev2 ? triangle[i][j] + prev1 : triangle[i][j] + prev2;
        }
        
        dp.push_back(temp);
    }
    
    int _max = 0;
    int last = dp.size() - 1;
    for(auto x : dp[last]){
        if(x > _max) _max = x;
    }
    
    return _max;
}