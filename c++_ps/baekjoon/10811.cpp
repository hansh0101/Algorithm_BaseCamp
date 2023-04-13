#include <iostream>
using namespace std;

int arr[101];
int n, m;
int idx1, idx2;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    // input
    cin >> n >> m;

    // init
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++) {
        // input
        cin >> idx1 >> idx2;
        // solve
        for (int j = idx1; j <= idx1 + (idx2 - idx1) / 2; j++) {
            swap(arr[j], arr[idx2 - (j - idx1)]);
        }
    }

    // output
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    return 0;
}