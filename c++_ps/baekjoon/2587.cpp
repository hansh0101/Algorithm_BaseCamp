#include <iostream>
#include <algorithm>
using namespace std;

int arr[5];
int sum;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 5; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < 4; i++) {
        int idx = i;
        for (int j = i + 1; j < 5; j++) {
            if (arr[idx] > arr[j]) {
                swap(arr[idx], arr[j]);
            }
        }
    }

    cout << sum / 5 << "\n" << arr[2];
    return 0;
}