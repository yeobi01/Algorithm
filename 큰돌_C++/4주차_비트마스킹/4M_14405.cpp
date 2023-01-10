#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

string s;
bool flag = true;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> s; 
    for(int i = 0; i < s.size(); ){
        if(s.substr(i, 2) == "pi") i += 2;
        else if(s.substr(i, 2) == "ka") i += 2;
        else if(s.substr(i, 3) == "chu") i += 3;
        else { flag = false; break; }
    }

    if(flag) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}