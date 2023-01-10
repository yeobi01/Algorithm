#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

string string_add(string a, string b){
    int sum = 0;
    string ret;
    while(a.size() || b.size() || sum){
        if(a.size()){
            sum += a.back() - '0';
            a.pop_back();
        }
        if(b.size()){
            sum += b.back() - '0';
            b.pop_back();
        }
        ret += (sum % 10) + '0';
        sum /= 10;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;
    cout << string_add(s1, s2) << "\n";
    return 0;
}