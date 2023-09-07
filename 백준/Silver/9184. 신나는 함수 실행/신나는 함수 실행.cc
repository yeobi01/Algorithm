#include <bits/stdc++.h>
using namespace std;

int w(int a, int b, int c, vector<vector<vector<int>>>& memo) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }
    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20, memo);
    }
    if (a < b && b < c) {
        if (memo[a][b][c] != -1) {
            return memo[a][b][c];
        }
        int result = w(a, b, c - 1, memo) + w(a, b - 1, c - 1, memo) - w(a, b - 1, c, memo);
        memo[a][b][c] = result;
        return result;
    }
    if (memo[a][b][c] != -1) {
        return memo[a][b][c];
    }
    int result = w(a - 1, b, c, memo) + w(a - 1, b - 1, c, memo) + w(a - 1, b, c - 1, memo) - w(a - 1, b - 1, c - 1, memo);
    memo[a][b][c] = result;
    return result;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        int a, b, c;
        vector<vector<vector<int>>> memo(21, vector<vector<int>>(21, vector<int>(21, -1)));
        cin >> a >> b >> c;
        if(a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c, memo) << "\n";
    }

    return 0;
}
