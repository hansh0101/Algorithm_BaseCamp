#include <iostream>
#include <algorithm>
using namespace std;

int n, s;
int arr[20];
int ans;

void solution(int sum, int idx, int size) {
    if(idx == n) {
        if(sum == s && size != 0) ans++;
        return;
    }

    solution(sum + arr[idx], idx+1, size+1);
    solution(sum, idx+1, size);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>s;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    sort(arr, arr+n);

    solution(0, 0, 0);
    cout<<ans;
    return 0;
}