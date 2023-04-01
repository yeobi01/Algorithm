#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

struct Time{
    int h;
    int m;
    int s;
};

int N;
vector<Time> arr;

bool cmp(Time a, Time b){
    if(a.h != b.h){
        return a.h < b.h;
    } else{
        if(a.m != b.m){
            return a.m < b.m;
        } else {
            return a.s < b.s;
        }
    }
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    cin >> N;
    for(int i = 0; i < N; i++){
        Time temp; cin >> temp.h >> temp.m >> temp.s;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), cmp);
    for(int i = 0; i < N; i++){
        cout << arr[i].h << " " << arr[i].m << " " << arr[i].s << "\n";
    }
    return 0;
}