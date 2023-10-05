#include <bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;	cin>>n;
	int qual[n];
	for(int i = 0 ; i < n ;) cin>>qual[i++];
	sort(qual,qual+n);
	
	int max_profit = 0; 
	for(int i = n-1 ;  i >= (int)((n+1)/2) ; i-- ){
		max_profit += qual[i];
	} 

	max_profit = (n%2==0) ? max_profit*2 : max_profit*2 + qual[n/2]; 
	cout<<max_profit;
}