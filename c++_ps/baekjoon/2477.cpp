#include <iostream>

using namespace std;

int k;
pair<int, int> arr[6];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> k;
    int max1 = 0, max2 = 0;
    int index1 = -1, index2 = -1;
    for (int i = 0; i < 6; i++) {
        cin >> arr[i].first >> arr[i].second;
    }

    for (int i = 0; i < 6; i++) {
        if (max1 <= arr[i].second) {
            max1 = arr[i].second;
            index1 = i;
        }
    }

    int left = index1 - 1;
    int right = index1 + 1;
    if (left == -1) {
        left = 5;
    }
    if (right == 6) {
        right = 0;
    }
    if (arr[left].second > arr[right].second) {
        max2 = arr[left].second;
        index2 = left;
    } else {
        max2 = arr[right].second;
        index2 = right;
    }

    if ((index2 + 1) % 6 == index1) {
        swap(index1, index2);
    }

    int index3 = index1, index4 = index2;
    index3 = index1 - 2;
    if (index3 < 0) {
        index3 = 6 + index3;
    }
    index4 = index2 + 2;
    if (index4 > 5) {
        index4 = index4 - 6;
    }

    cout << (arr[index1].second * arr[index2].second - arr[index3].second * arr[index4].second) * k << "\n";
    return 0;
}