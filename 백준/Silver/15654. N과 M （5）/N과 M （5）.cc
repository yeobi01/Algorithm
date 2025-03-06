#include <bits/stdc++.h>
using namespace std;
#define MAX 9

int N, M;
int arr[MAX] = {0,};
bool visited[MAX] = {0,};
vector<int> v;

void dfs(int num, int cnt)
{
    if(cnt == M)
    {
        for(int i = 0; i < M; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = num; i <= N; i++)
    {
    	if(!visited[i]){
    		visited[i] = true;
    		arr[cnt] = v[i - 1];
        	dfs(1,cnt+1);
        	visited[i] = false;
		}
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	
	cin >> N >> M;
	
	int tmp;
	for(int i = 0; i < N; i++){
		cin >> tmp;
		v.push_back(tmp);
	}
	
	
	sort(v.begin(), v.end());
	
    dfs(1,0);
	
}