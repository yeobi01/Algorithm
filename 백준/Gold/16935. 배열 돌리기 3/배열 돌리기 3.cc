#include <bits/stdc++.h>
using namespace std;

int n, m, op_count;
int arr[100][100], temp[100][100];
vector<int> op;

void t2a_copy(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            arr[i][j] = temp[i][j];
        }
    }
}

void op_1(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = arr[n - i - 1][j];
        }
    }
    t2a_copy();
}

void op_2(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[i][j] = arr[i][m - j - 1];
        }
    }
    t2a_copy();
}

void op_3(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[j][n - i - 1] = arr[i][j];
        }
    }
    int t = m; m = n; n = t;
    t2a_copy();
}

void op_4(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            temp[m - j - 1][i] = arr[i][j];
        }
    }
    int t = m; m = n; n = t;
    t2a_copy();
}

void op_5(){
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < m/2; j++){
            temp[i][j + m/2] = arr[i][j];
        }
    }
    for(int i = 0; i < n/2; i++){
        for(int j = m/2; j < m; j++){
            temp[i + n/2][j] = arr[i][j];
        }
    }
    for(int i = n/2; i < n; i++){
        for(int j = m/2; j < m; j++){
            temp[i][j - m/2] = arr[i][j];
        }
    }
    for(int i = n/2; i < n; i++){
        for(int j = 0; j < m/2; j++){
            temp[i - n/2][j] = arr[i][j];
        }
    }
    t2a_copy();
}

void op_6(){
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < m/2; j++){
            temp[i + n/2][j] = arr[i][j];
        }
    }
    for(int i = 0; i < n/2; i++){
        for(int j = m/2; j < m; j++){
            temp[i][j - m/2] = arr[i][j];
        }
    }
    for(int i = n/2; i < n; i++){
        for(int j = m/2; j < m; j++){
            temp[i - n/2][j] = arr[i][j];
        }
    }
    for(int i = n/2; i < n; i++){
        for(int j = 0; j < m/2; j++){
            temp[i][j + m/2] = arr[i][j];
        }
    }
    t2a_copy();
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin >> n >> m >> op_count;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> arr[i][j];
        }
    }
    for(int i = 0; i < op_count; i++){
        int temp; cin >> temp;
        op.push_back(temp);
    }

    for(auto x : op){
        switch(x){
            case 1:
                op_1();
                break;
            case 2:
                op_2();
                break;
            case 3:
                op_3();
                break;
            case 4:
                op_4();
                break;
            case 5:
                op_5();
                break;
            case 6:
                op_6();
                break;
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << arr[i][j] << " ";
        } cout << "\n";
    }

    return 0;
}