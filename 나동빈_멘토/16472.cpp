#include<bits/stdc++.h>
using namespace std;   
typedef long long ll;
const int INF = 987654321;

int N, check[27], ret;
string s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    cin >> s;

    int low = 0, high = 0, cnt = 1;
    check[s[0] - 'a']++;
    while(high < s.size() - 1){
        if(cnt < N){
            high++;
            if(!check[s[high] - 'a']) cnt++;
            check[s[high] - 'a']++;
        } else if(cnt == N){
            if(check[s[high + 1] - 'a']){
                high++;
                check[s[high] - 'a']++;
            } else {
                check[s[low] - 'a']--;
                if(!check[s[low] - 'a']) cnt--;
                low++;
            }
        }
        ret = max(ret, high - low + 1);
    }
    cout << ret << "\n";
    return 0;
}