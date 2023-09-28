#include <bits/stdc++.h>
using namespace std;

int arr[10][10];
int paper[6] = {0, 5, 5, 5, 5, 5};
int ans = 987654321;

bool check5(int y, int x){
    if(y + 5 > 10 || x + 5 > 10) return false;

    for(int i = y; i < y + 5; i++){
        for(int j = x; j < x + 5; j++){
            if(!arr[i][j]) return false;
        }
    }
    return true;
}

bool check4(int y, int x){
    if(y + 4 > 10 || x + 4 > 10) return false;

    for(int i = y; i < y + 4; i++){
        for(int j = x; j < x + 4; j++){
            if(!arr[i][j]) return false;
        }
    }
    return true;
}

bool check3(int y, int x){
    if(y + 3 > 10 || x + 3 > 10) return false;

    for(int i = y; i < y + 3; i++){
        for(int j = x; j < x + 3; j++){
            if(!arr[i][j]) return false;
        }
    }
    return true;
}

bool check2(int y, int x){
    if(y + 2 > 10 || x + 2 > 10) return false;

    for(int i = y; i < y + 2; i++){
        for(int j = x; j < x + 2; j++){
            if(!arr[i][j]) return false;
        }
    }
    return true;
}

int count_paper_size(int y, int x){
    int ret = 1;

    if(check2(y, x)) ret = 2;    
    if(check3(y, x)) ret = 3;
    if(check4(y, x)) ret = 4;
    if(check5(y, x)) ret = 5;
    
    return ret;
}

void fill(int y, int x, int size){
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            arr[i][j] = 1;
        }
    }
    return;
}

void erase(int y, int x, int size){
    for(int i = y; i < y + size; i++){
        for(int j = x; j < x + size; j++){
            arr[i][j] = 0;
        }
    }
    return;
}

bool check(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            if(arr[i][j]) return false;
        }
    }
    return true;
}

void debug(){
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void solve(int y, int x, int cnt){
    bool flag = true;
    for(int i = 0; flag && i < 10; i++){
        for(int j = 0; flag && j < 10; j++){
            if(!arr[i][j]) continue;
            
            // cout << i << " " << j << "\n";
            int put_paper_num = count_paper_size(i, j);
            for(int t = put_paper_num; t > 0; t--){
                if(!paper[t]) continue;
                
                paper[t]--;
                erase(i, j, t);

                // cout << i << j << " " << paper[t] << " " << t << " " << cnt << "\n";
                // debug();

                // cout << i << " " << j << " " << cnt + 1 << "\n";
                solve(i, j, cnt + 1);

                paper[t]++;
                fill(i, j, t);
            }
            
            flag = false;
        }
    }

    if(check()){
        // cout << cnt << "\n";
        ans = min(ans, cnt);
    }
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++){
            cin >> arr[i][j];
        }
    }

    solve(0, 0, 0);
    
    if(ans != 987654321) cout << ans << "\n";
    else cout << "-1\n";

    return 0;
}
