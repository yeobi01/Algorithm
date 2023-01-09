#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, 0, -1, 1};
const int dx[4] = {1, -1, 0, 0};

int N, L, a[104][104], b[104][104], ret;

void solve(int arr[104][104]){
	for(int i = 0; i < N; i++){
		int cnt = 1;
		int j;
		for(j = 0; j < N - 1; j++){
			if(arr[i][j] == arr[i][j + 1]) cnt++;
			else if((arr[i][j] + 1 == arr[i][j + 1]) && cnt >= L) cnt = 1;
			else if((arr[i][j] - 1 == arr[i][j + 1]) && cnt >= 0) cnt = 1 - L;
			else break;
		}
		if(j == N - 1 && cnt >= 0) ret++;
	}
	return;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> a[i][j];
			b[j][i] = a[i][j];
		}
	}
	solve(a); solve(b);
	cout << ret << "\n";
    return 0;
}