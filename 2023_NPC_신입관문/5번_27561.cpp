#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int N, arr[100001], G_front = -1, H_front = -1, G_back, H_back, ret;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> s;
    for(int i = 0; i < N; i++){
        cin >> arr[i]; arr[i]--;
        (G_front == -1 && s[i] == 'G') ? G_front = i : NULL;
        (H_front == -1 && s[i] == 'H') ? H_front = i : NULL;
        s[i] == 'G' ? G_back = i : NULL;
        s[i] == 'H' ? H_back = i : NULL;
    }
    if(arr[G_front] >= G_back){
        for(int i = 0; i < G_front; i++){
            if(i == H_front) continue;
            if(s[i] == 'H' && arr[i] >= G_front) ret++;
        }
    }
    if(arr[H_front] >= H_back){
        for(int i = 0; i < H_front; i++){
            if(i == G_front) continue;
            if(s[i] == 'G' && arr[i] >= H_front) ret++;
        }
    }
    if(arr[G_front] >= G_back || arr[H_front] >= H_back) ret++;

    cout << ret << "\n";
    return 0;
}