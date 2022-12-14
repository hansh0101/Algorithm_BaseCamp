#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10001];

void solution() {
    int s = 0, e = 0;
    int sum = arr[s];
    int ans = 0;

    while(e!=n) {
        if(sum == m) {
            ans++;
            e++;
            if(e!=n) {
                sum += arr[e];
            }
            sum-=arr[s];
            s++;
        }
        else if(sum > m) {
            sum -= arr[s];
            s++;
        }
        else if(sum < m) {
            e++;
            if(e!=n) {
                sum+=arr[e];
            }
        }
    }
    cout<<ans;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin>>n>>m;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }

    solution();
    return 0;
}