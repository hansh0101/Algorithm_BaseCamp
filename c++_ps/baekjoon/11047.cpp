#include <iostream>
using namespace std;

int n, k, ans;
int arr[10];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>k;
    for(int i=n-1;i>=0;i--){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++) {
        if (arr[i] > k) {
            continue;
        }

        ans += k / arr[i];
        k = k % arr[i];
    }

    cout<<ans;
    return 0;
}