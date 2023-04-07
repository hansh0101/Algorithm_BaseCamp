#include <iostream>
using namespace std;

int arr[101];
int n, m;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int start, end, num;
        cin >> start >> end >> num;

        for (int j = start; j <= end; j++) {
            arr[j] = num;
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}