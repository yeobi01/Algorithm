#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int T;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for(int t = 0; t < T; t++){
		string s;  cin >> s;
		int n ; cin >> n;

		deque<int> dq; char temp; int a;
		for(int i = 0; i < n; i++){
			cin >> temp >> a;
			dq.push_back(a);
		} cin >> temp;
		if(n == 0) cin >> temp;

		bool error = false, rev = false;
		for(char temp : s){
			if(temp == 'R'){ rev = !rev; }
			else if(temp == 'D'){
				if(dq.empty()){
					error = true;
					break;
				}
				if(rev) dq.pop_back();
				else dq.pop_front();
			}
		}

		if(error) cout << "error\n";
		else{
			if(rev) reverse(dq.begin(), dq.end());

			cout << '[';
			for(int i = 0; i < dq.size(); i++){
				cout << dq[i];
				if(i < dq.size() - 1) cout << ",";
			}
			cout << "]\n";
		}
	}

    return 0;
}