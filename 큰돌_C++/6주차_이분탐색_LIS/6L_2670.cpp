#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

int N;
double arr[10001], ret, b;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    b = arr[0];
    for(int i = 1; i < N; i++){
        if(arr[i] > b * arr[i]) b = arr[i];
        else b *= arr[i];
        ret = max(b, ret);
    }
    printf("%.3lf", ret);
    return 0;
}