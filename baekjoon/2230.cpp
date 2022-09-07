#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[100001];

void solution() {
    int start = 0, end = 0;
    int res = 2*1e9;
    while (start != n - 1) {
        int sub = arr[end]-arr[start];
        if(sub >= m) {
            res = min(res, sub);
            start++;
        }
        else if(sub < m) {
            end++;
        }
    }
    cout<<res;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    solution();
}