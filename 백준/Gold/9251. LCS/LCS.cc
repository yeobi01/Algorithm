#include <bits/stdc++.h>
using namespace std;

string s1, s2;
int s1_len, s2_len;
int ans[1001][1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s1 >> s2;
    
    s1_len = s1.size();
    s2_len = s2.size();
    for(int i = 1; i <= s1_len; i++){
        for(int j = 1; j <= s2_len; j++){
            if(s1[i - 1] == s2[j - 1]) 
                ans[i][j] = ans[i - 1][j - 1] + 1;
            else
                ans[i][j] = max(ans[i - 1][j], ans[i][j - 1]);
        }
    }

    cout << ans[s1_len][s2_len] << "\n";

    return 0;
}
