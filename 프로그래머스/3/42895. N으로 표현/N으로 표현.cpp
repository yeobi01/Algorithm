#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int solution(int N, int number) {
    vector<vector<int>> dp;
    
    dp.push_back({0});
    dp.push_back({N});
    
    if(number == N) return 1;
    
    for(int i = 2; i <= 9; i++){
        vector<int> temp;
        
        int hi = 0;
        for(int k = 0; k < i; k++){
            hi += N * pow(10, k);
        }
        temp.push_back(hi);
        
        for(int j = 1; j < i; j++){
            for(int m = 0; m < dp[j].size(); m++){
                for(int n = 0; n < dp[i - j].size(); n++){
                    if(dp[i - j][n] == 0) continue;
                    
                    int plus = dp[j][m] + dp[i - j][n];
                    int minus = dp[j][m] - dp[i - j][n];
                    int mul = dp[j][m] * dp[i - j][n];
                    int div = dp[j][m] / dp[i - j][n];
                    if(plus > 0 && plus <= 32000) temp.push_back(plus);
                    if(minus > 0 && minus <= 32000) temp.push_back(minus);
                    if(mul > 0 && mul <= 32000) temp.push_back(mul);
                    if(div > 0 && div <= 32000) temp.push_back(div);
                }
            }
        }
        
        for(int x : temp){
            if(x == number) return i;
        }
        
        dp.push_back(temp);
    }
    
    return -1;
}

/*



*/