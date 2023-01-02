#include <bits/stdc++.h>
using namespace std;

int N;
char a[65][65];

string quard(int y, int x, int size){
    string ret = "";
    char temp = a[y][x];

    if(size == 1) { ret += temp; return ret; }
    
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            if(temp != a[i][j]){
                ret += '(';
                ret += quard(y, x, size/2);
                ret += quard(y, x + size/2, size/2);
                ret += quard(y + size/2, x, size/2);
                ret += quard(y + size/2, x + size/2, size/2);
                ret += ')';
                return ret;
            }
        }
    }

    ret += temp;
    return ret;
} 

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    }
    cout << quard(0, 0, N) << "\n";
    return 0;
}