#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

int N, M;
bool visited[251];
vector<int> v[251];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for(int i = 0; i < M; i++){
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	queue<int> q;
	q.push(1);
	while(!q.empty()){
		int cur = q.front(); q.pop();
		visited[cur] = true;  
		for(int temp : v[cur]){
			if(!visited[temp]) q.push(temp);
		}
	}

	bool flag = false;
	for(int i = 1; i <= N; i++){
		if(!visited[i]) { cout << i << "\n"; flag = true; }
	}
	if(!flag) cout << "0\n";

    return 0;
}