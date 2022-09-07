#include <iostream>
#include <algorithm>

using namespace std;

int n, c;
int arr[200001];

void solution() {
    int l = 1;
    int r = arr[n-1] - arr[0];
    int ans = -1;

    while(l<=r) {
        int m = (l+r)/2;
        int idx = 0;
        int iptime = 1;

        for(int i=1;i<n;i++) {
            if(arr[i] - arr[idx] >= m) {
                idx = i;
                iptime++;
            }
        }

        if(iptime >= c) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }

        if(iptime >= c) {
            ans = max(ans, m);
        }
    }
    cout<<ans;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    solution();
    return 0;
}