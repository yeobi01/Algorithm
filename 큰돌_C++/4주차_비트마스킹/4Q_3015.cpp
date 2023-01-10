#include<bits/stdc++.h>
using namespace std;  
typedef long long ll;
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

ll N, temp, ret;
stack<pair<ll, ll>> stk;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> temp;
        int cnt = 1;
        while(!stk.empty() && stk.top().first <= temp){
            ret += stk.top().second;
            if(stk.top().first == temp){
                cnt = stk.top().second + 1;
            } else{
                cnt = 1;
            }
            stk.pop();
        }
        if(stk.size()) ret++;
        stk.push({temp, cnt});
    }
    cout << ret << "\n";
    return 0;
}
/*
7
2
6
1
2
2
5
1
*/