#include <bits/stdc++.h>
using namespace std;

int N, team, score_1, score_2;
int time_1, time_2;
string s, temp = "00:00";

string print(int x){
    string m = "00" + to_string(x / 60);
    string s = "00" + to_string(x % 60);
    return m.substr(m.size()-2, 2) + ":" + s.substr(s.size()-2, 2);
}

int changeToInt(string a){
    return atoi(a.substr(0,2).c_str()) * 60 + atoi(a.substr(3,2).c_str());
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> team >> s;
        if(score_1 > score_2){
            time_1 += changeToInt(s) - changeToInt(temp);
        } else if(score_2 > score_1){
            time_2 += changeToInt(s) - changeToInt(temp);
        }
        team == 1 ? score_1++ : score_2++;
        temp = s;
    }

    s = "48:00";
    if(score_1 > score_2){
            time_1 += changeToInt(s) - changeToInt(temp);
    } else if(score_2 > score_1){
            time_2 += changeToInt(s) - changeToInt(temp);
    }
    
    cout << print(time_1) << "\n";
    cout << print(time_2) << "\n";
    return 0;
}