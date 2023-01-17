#include <iostream>

using namespace std;

int arr[8];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 8; i++) {
        cin >> arr[i];
    }

    bool isAscending = true, isDescending = true;
    for (int i = 1; i < 8; i++) {
        if (arr[i - 1] < arr[i]) {
            isDescending = false;
        } else if (arr[i - 1] > arr[i]) {
            isAscending = false;
        }
    }

    if (!isAscending && !isDescending) {
        cout << "mixed\n";
    } else {
        if (isAscending) {
            cout << "ascending\n";
        } else if (isDescending) {
            cout << "descending\n";
        }
    }

    return 0;
}