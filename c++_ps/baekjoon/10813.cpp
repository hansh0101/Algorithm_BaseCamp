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

    // solve
    for (int i = 1; i <= n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> idx1 >> idx2;
        swap(arr[idx1], arr[idx2]);
    }

    // output
    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}