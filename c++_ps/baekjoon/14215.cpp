#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 3; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + 3);

    if (arr[2] < arr[0] + arr[1]) {
        cout << arr[0] + arr[1] + arr[2] << "\n";
        return 0;
    }

    cout << (arr[0] + arr[1]) * 2 - 1 << "\n";
    return 0;
}