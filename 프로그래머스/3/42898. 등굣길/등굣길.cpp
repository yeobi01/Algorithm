#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int dp[n][m];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            dp[i][j] = 0;
        }
    }
    for(vector<int> x : puddles){
        dp[x[1] - 1][x[0] - 1] = -1;
    }
    
    dp[0][0] = 1;
    for(int i = 1; i < n; i++){
        if(dp[i][0] != -1) dp[i][0] = dp[i - 1][0];
    }
    for(int i = 1; i < m; i++){
        if(dp[0][i] != -1) dp[0][i] = dp[0][i - 1];
    }
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            int a = dp[i][j - 1];
            int b = dp[i - 1][j];
            
            if(dp[i][j] == -1) continue;
            
            if(a == -1 && b == -1) dp[i][j] = -1;
            else if(a == -1) dp[i][j] = b;
            else if(b == -1) dp[i][j] = a;
            else dp[i][j] = a + b;
            
            dp[i][j] %= 1000000007;
        }
    }
    
    if(dp[n - 1][m - 1] == -1) dp[n - 1][m - 1] = 0; 
    return dp[n - 1][m - 1];
}