#include <iostream>
#include <algorithm>
using namespace std;

int k, n;
int arr[10001];

void solution() {
    long long l = 1;
    long long r = arr[k-1];
    long long res = 0;

    while(r>=l) {
        long long sum = 0;
        long long mid = (l+r)/2;
        for(int i=0;i<k;i++) {
            sum += arr[i]/mid;
        }
        if(sum >= n) {
            res = mid;
            l = mid + 1;
        }
        if(sum < n) {
            r = mid - 1;
        }
    }
    cout<<res;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>k>>n;
    for(int i=0;i<k;i++) {
        cin>>arr[i];
    }
    sort(arr, arr+k);
    solution();
    return 0;
}