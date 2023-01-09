#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int N, temp, num;
string s;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> s;
        if(s == "add"){
            cin >> temp;
            num |= (1 << temp);
        } else if(s == "remove"){
            cin >> temp;
            num &= ~(1 << temp);
        } else if(s == "check"){
            cin >> temp;
            if(num & (1 << temp)) cout << "1\n";
            else cout << "0\n";
        } else if(s == "toggle"){
            cin >> temp;
            if(num & (1 << temp)) num &= ~(1 << temp);
            else num |= (1 << temp);
        } else if(s == "all"){
            num = pow(2, 21) - 1;
        } else if(s == "empty"){
            num = 0;
        }
    }
    return 0;
}