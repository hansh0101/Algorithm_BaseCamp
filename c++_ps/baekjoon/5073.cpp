#include <iostream>
#include <algorithm>

using namespace std;

int arr[3];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true) {
        for (int i = 0; i < 3; i++) {
            cin >> arr[i];
        }

        sort(arr, arr + 3);
        
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
            break;
        }

        if (arr[2] >= arr[1] + arr[0]) {
            cout << "Invalid\n";
            continue;
        }

        if (arr[2] == arr[1] && arr[1] == arr[0]) {
            cout << "Equilateral\n";
            continue;
        }

        if (arr[2] == arr[1] || arr[1] == arr[0]) {
            cout << "Isosceles\n";
            continue;
        }

        cout << "Scalene\n";
        continue;
    }

    return 0;
}