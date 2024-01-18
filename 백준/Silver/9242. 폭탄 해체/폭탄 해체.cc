#include <bits/stdc++.h>
using namespace std;

int arr[31][5];
int n;
int code;

int check_number(int x, int y);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 5; i++){
        string s; getline(cin, s);
        n = s.length();
        for(int j = 0; j < s.length(); j++){
            arr[j][i] = s[j];
        }
    }

    for(int i = 0; i < n; i += 4){
        int temp = check_number(i, 0);
        if(temp != -1){
            code = code * 10 + temp;
        } else {
            cout << "BOOM!!\n";
            return 0;
        }
    }

    if(code % 6 == 0) cout << "BEER!!\n";
    else cout << "BOOM!!\n";

    return 0;
}

int check_number(int x, int y){
    if(arr[x][y] == '*' && arr[x + 1][y] == '*' && arr[x + 2][y] == '*'
        && arr[x][y + 1] == '*' && arr[x + 1][y + 1] == ' ' && arr[x + 2][y + 1] == '*'
        && arr[x][y + 2] == '*' && arr[x + 1][y + 2] == ' ' && arr[x + 2][y + 2] == '*'
        && arr[x][y + 3] == '*' && arr[x + 1][y + 3] == ' ' && arr[x + 2][y + 3] == '*'
        && arr[x][y + 4] == '*' && arr[x + 1][y + 4] == '*' && arr[x + 2][y + 4] == '*'
    ){
        return 0;
    } else if(arr[x][y] == ' ' && arr[x + 1][y] == ' ' && arr[x + 2][y] == '*'
        && arr[x][y + 1] == ' ' && arr[x + 1][y + 1] == ' ' && arr[x + 2][y + 1] == '*'
        && arr[x][y + 2] == ' ' && arr[x + 1][y + 2] == ' ' && arr[x + 2][y + 2] == '*'
        && arr[x][y + 3] == ' ' && arr[x + 1][y + 3] == ' ' && arr[x + 2][y + 3] == '*'
        && arr[x][y + 4] == ' ' && arr[x + 1][y + 4] == ' ' && arr[x + 2][y + 4] == '*'
    ){
        return 1;
    } else if(arr[x][y] == '*' && arr[x + 1][y] == '*' && arr[x + 2][y] == '*'
        && arr[x][y + 1] == ' ' && arr[x + 1][y + 1] == ' ' && arr[x + 2][y + 1] == '*'
        && arr[x][y + 2] == '*' && arr[x + 1][y + 2] == '*' && arr[x + 2][y + 2] == '*'
        && arr[x][y + 3] == '*' && arr[x + 1][y + 3] == ' ' && arr[x + 2][y + 3] == ' '
        && arr[x][y + 4] == '*' && arr[x + 1][y + 4] == '*' && arr[x + 2][y + 4] == '*'
    ){
        return 2;
    } else if(arr[x][y] == '*' && arr[x + 1][y] == '*' && arr[x + 2][y] == '*'
        && arr[x][y + 1] == ' ' && arr[x + 1][y + 1] == ' ' && arr[x + 2][y + 1] == '*'
        && arr[x][y + 2] == '*' && arr[x + 1][y + 2] == '*' && arr[x + 2][y + 2] == '*'
        && arr[x][y + 3] == ' ' && arr[x + 1][y + 3] == ' ' && arr[x + 2][y + 3] == '*'
        && arr[x][y + 4] == '*' && arr[x + 1][y + 4] == '*' && arr[x + 2][y + 4] == '*'
    ){
        return 3;
    } else if(arr[x][y] == '*' && arr[x + 1][y] == ' ' && arr[x + 2][y] == '*'
        && arr[x][y + 1] == '*' && arr[x + 1][y + 1] == ' ' && arr[x + 2][y + 1] == '*'
        && arr[x][y + 2] == '*' && arr[x + 1][y + 2] == '*' && arr[x + 2][y + 2] == '*'
        && arr[x][y + 3] == ' ' && arr[x + 1][y + 3] == ' ' && arr[x + 2][y + 3] == '*'
        && arr[x][y + 4] == ' ' && arr[x + 1][y + 4] == ' ' && arr[x + 2][y + 4] == '*'
    ){
        return 4;
    } else if(arr[x][y] == '*' && arr[x + 1][y] == '*' && arr[x + 2][y] == '*'
        && arr[x][y + 1] == '*' && arr[x + 1][y + 1] == ' ' && arr[x + 2][y + 1] == ' '
        && arr[x][y + 2] == '*' && arr[x + 1][y + 2] == '*' && arr[x + 2][y + 2] == '*'
        && arr[x][y + 3] == ' ' && arr[x + 1][y + 3] == ' ' && arr[x + 2][y + 3] == '*'
        && arr[x][y + 4] == '*' && arr[x + 1][y + 4] == '*' && arr[x + 2][y + 4] == '*'
    ){
        return 5;
    } else if(arr[x][y] == '*' && arr[x + 1][y] == '*' && arr[x + 2][y] == '*'
        && arr[x][y + 1] == '*' && arr[x + 1][y + 1] == ' ' && arr[x + 2][y + 1] == ' '
        && arr[x][y + 2] == '*' && arr[x + 1][y + 2] == '*' && arr[x + 2][y + 2] == '*'
        && arr[x][y + 3] == '*' && arr[x + 1][y + 3] == ' ' && arr[x + 2][y + 3] == '*'
        && arr[x][y + 4] == '*' && arr[x + 1][y + 4] == '*' && arr[x + 2][y + 4] == '*'
    ){
        return 6;
    } else if(arr[x][y] == '*' && arr[x + 1][y] == '*' && arr[x + 2][y] == '*'
        && arr[x][y + 1] == ' ' && arr[x + 1][y + 1] == ' ' && arr[x + 2][y + 1] == '*'
        && arr[x][y + 2] == ' ' && arr[x + 1][y + 2] == ' ' && arr[x + 2][y + 2] == '*'
        && arr[x][y + 3] == ' ' && arr[x + 1][y + 3] == ' ' && arr[x + 2][y + 3] == '*'
        && arr[x][y + 4] == ' ' && arr[x + 1][y + 4] == ' ' && arr[x + 2][y + 4] == '*'
    ){
        return 7;
    } else if(arr[x][y] == '*' && arr[x + 1][y] == '*' && arr[x + 2][y] == '*'
        && arr[x][y + 1] == '*' && arr[x + 1][y + 1] == ' ' && arr[x + 2][y + 1] == '*'
        && arr[x][y + 2] == '*' && arr[x + 1][y + 2] == '*' && arr[x + 2][y + 2] == '*'
        && arr[x][y + 3] == '*' && arr[x + 1][y + 3] == ' ' && arr[x + 2][y + 3] == '*'
        && arr[x][y + 4] == '*' && arr[x + 1][y + 4] == '*' && arr[x + 2][y + 4] == '*'
    ){
        return 8;
    } else if(arr[x][y] == '*' && arr[x + 1][y] == '*' && arr[x + 2][y] == '*'
        && arr[x][y + 1] == '*' && arr[x + 1][y + 1] == ' ' && arr[x + 2][y + 1] == '*'
        && arr[x][y + 2] == '*' && arr[x + 1][y + 2] == '*' && arr[x + 2][y + 2] == '*'
        && arr[x][y + 3] == ' ' && arr[x + 1][y + 3] == ' ' && arr[x + 2][y + 3] == '*'
        && arr[x][y + 4] == '*' && arr[x + 1][y + 4] == '*' && arr[x + 2][y + 4] == '*'
    ){
        return 9;
    } else {
        return -1;
    }
}
