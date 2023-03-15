#include <bits/stdc++.h>
using namespace std;

char a[3][3], b[3][3];
int check[27], visited[27], green, yellow;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> b[i][j];
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(a[i][j] == b[i][j]) green++;
        }
    }
    for(char c = 'A'; c <= 'Z'; c++){
        int a_count = 0, b_count = 0;
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(a[i][j] == c) a_count++;
                if(b[i][j] == c) b_count++;
            }
        }
        yellow += min(a_count, b_count);
    }
    cout << green << "\n" << yellow - green << "\n";
    return 0;
}
