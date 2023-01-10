#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int N, ret;
string s;
stack<int> stk;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N >> s;
    stk.push(-1);
    for(int i = 0; i < N; i++){
        if(s[i] == '(') stk.push(i);
        else{
            stk.pop();
            if(!stk.empty()) ret = max(ret, i - stk.top());
            else stk.push(i);
        }
    }
    cout << ret << "\n";
    return 0;
}