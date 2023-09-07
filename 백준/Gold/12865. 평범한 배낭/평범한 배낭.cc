#include <bits/stdc++.h>
using namespace std;

int N, K;
int mass[101];
int value[101];
int ans[101][100001];

void sovle(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= K; j++){
			if(mass[i] <= j) ans[i][j] = max(ans[i-1][j], ans[i-1][j-mass[i]] + value[i]);
			else ans[i][j] = ans[i-1][j];
		}
	}
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> N >> K;
	for(int i = 1; i <= N; i++){
		cin >> mass[i] >> value[i];
	}
	
	sovle();
	
	cout << ans[N][K] << endl;
}

