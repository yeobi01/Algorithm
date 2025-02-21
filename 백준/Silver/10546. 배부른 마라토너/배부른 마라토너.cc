#include <iostream>
#include <algorithm>
using namespace std;

int N;
string arr[100000];
string arr2[100000];

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < N - 1; i++){
        cin >> arr2[i];
    }
    sort(arr, arr + N);
    sort(arr2, arr2 + N - 1);
    for(int i = 0; i < N; i++){
        if(arr[i].compare(arr2[i])){
            cout << arr[i] << "\n";
            return 0;
        }
    }
    return 0;
}