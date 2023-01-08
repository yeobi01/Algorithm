#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;

int N, arr[21], ret = INF;
string s;

void go(int here){
	if(here == N){
		int sum = 0;
		for(int i = 0; i < N; i++){
			int bit = (1 << i);
			int cnt = 0;
			for(int j = 0; j < N; j++){
				if(arr[j] & bit) cnt++;
			}
			sum += min(cnt, N - cnt);
		}
		ret = min(ret, sum);
		return;
	}
	go(here + 1);
	arr[here] = ~arr[here];
	go(here + 1);
	return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for(int i = 0; i < N; i++){
		cin >> s;
		for(int j = 0; j < N; j++){
			if(s[j] == 'T') arr[i] |= (1 << j);
		}
	}
	go(0);
	cout << ret << "\n";
    return 0;
}