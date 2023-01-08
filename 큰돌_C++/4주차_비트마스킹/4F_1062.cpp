#include<bits/stdc++.h>
using namespace std;   
const int INF = 987654321;

int N, K, ret, words[51];
// vector<string> s_vec;

int countRead(int num){
    int cnt = 0;
    for(int i = 0; i < N; i++){
        if((words[i] & num) == words[i]) cnt++;
    }
    return cnt;
}

/*
int countRead(int num){
    int cnt = 0;
    for(string s : s_vec){
        bool flag = true;
        for(int i = 4; i < s.length() - 4; i++){
            int _temp = (1 << (int)(s[i] - 'a'));
            if((num & _temp) == 0) { flag = false; break; } 
        } // s[i]자리의 알바벳이 num의 비트자리가 켜져있으면 통과
        if(flag) cnt++;
    }
    return cnt;
}
*/

void DFS(int idx, int num, int cnt){
    if(cnt == K){
        ret = max(ret, countRead(num));
        return;
    }
    if(idx == 26) return;

    if(num & (1 << idx)){
        DFS(idx + 1, num, cnt);
    } else{
        DFS(idx + 1, num, cnt);
        num |= (1 << idx);
        DFS(idx + 1, num, cnt + 1);
    }
    return;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int learn = 0;
    learn |= (1 << (int)('a'-'a'));
    learn |= (1 << (int)('n'-'a'));
    learn |= (1 << (int)('t'-'a'));
    learn |= (1 << (int)('i'-'a'));
    learn |= (1 << (int)('c'-'a'));

    cin >> N >> K;
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        for(char c : s){
            words[i] |= (1 << (int)(c - 'a'));
        }
    }
    /*
    for(int i = 0; i < N; i++){
        string s; cin >> s;
        s_vec.push_back(s);
    }
    */
    if(K < 5){ cout << "0\n"; return 0; }

    DFS(0, learn, 5);
    cout << ret << "\n";
    return 0;
}
/*
a n t i c 
*/