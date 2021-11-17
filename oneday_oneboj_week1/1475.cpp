#include <iostream>
using namespace std;

int n;
int arr[10];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n;
    while(n != 0) {
        arr[n%10]++;
        n/=10;
    }
    int sum = arr[6]+arr[9];
    arr[6] = sum-sum/2;
    arr[9] = sum-arr[6];

    int ans = 0;
    for(int i=0;i<10;i++) {
        ans = max(ans, arr[i]);
    }
    cout<<ans;
    return 0;
}