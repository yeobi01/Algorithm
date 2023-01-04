#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

vector<int> num;
vector<char> oper_str;
int N, ret = -987654321;
string s;

int oper(char c, int a, int b){
    if(c == '+') return a + b;
    else if(c == '-') return a - b;
    else if(c == '*') return a * b;
}

void go(int x, int sum){
    if(x == num.size() - 1){
        ret = max(ret, sum);
        return;
    }
    go(x + 1, oper(oper_str[x], sum, num[x + 1]));
    if(x + 2 <= num.size() - 1){
        int temp = oper(oper_str[x + 1], num[x + 1], num[x + 2]);
        go(x + 2, oper(oper_str[x], sum, temp));
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> s;
    for(int i = 0; i < N; i++){
        if(i % 2 == 0) num.push_back(s[i] - '0');
        else oper_str.push_back(s[i]);
    }
    go(0, num[0]);

    cout << ret << "\n";
    return 0;
}