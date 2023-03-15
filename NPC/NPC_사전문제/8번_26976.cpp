#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;

int T, N, K;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> T;
    while(T--){
        char ret[100001]; for(int i = 0; i < 100001; i++) ret[i] = '.';
        bool visited[100001]; for(int i = 0; i < 100001; i++) visited[i] = false;
        cin >> N >> K >> s;
        
        int ans = 0;
        for(int i = 0; i < N; i++){
            if(visited[i]) continue;
            if(i + K < N && ret[i + K] == '.'){
                ret[i + K] = s[i]; ans++;
                for(int j = i; j <= i + 2 * K; j++){
                    if(s[i] == s[j]) visited[j] = true;
                }
            } else if(i + K >= N){
                ans++;
                if(ret[i] == '.'){
                    ret[i] = s[i];
                    for(int j = i; j <= N; j++){
                        if(s[i] == s[j]) visited[j] = true;
                    }
                } else if(ret[i] != s[i]){
                    ret[i - 1] = s[i];
                    for(int j = i - 1; j <= N; j++){
                        if(s[i] == s[j]) visited[j] = true;
                    }
                }
            }
        }
        cout << ans << "\n";
        for(int i = 0; i < N; i++) cout << ret[i];
        cout << "\n";
    }
    
    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--) {
		int n;
		int k;
		cin >> n >> k;
		string s;
		cin >> s;

		int patchG = -k - 1; // first patch location which does not cover cow 1
		int patchH = -k - 1; // first patch location which does not cover cow 1

		int cnt = 0;
		string ans(n, '.');

		for (int i = 0; i < n; i++) {
			if (s[i] == 'G' && i - patchG > k) {
				// the nearest G patch we placed does not cover cow i
				++cnt;
				if (i + k >= n) {
					patchG = i;
					if (ans[patchG] == 'H') { patchG--; }
				} else {
					patchG = i + k; // place the G patch k away
				}
				ans[patchG] = 'G';
			}
			if (s[i] == 'H' && i - patchH > k) {
				// the nearest H patch we placed does not cover cow i
				++cnt;
				if (i + k >= n) {
					patchH = i;
					if (ans[patchH] == 'G') { patchH--; }
				} else {
					patchH = i + k; // place the H patch k away
				}
				ans[patchH] = 'H';
			}
		}
		cout << cnt << endl << ans << endl;
	}
}
*/