#include <iostream>

using namespace std;

int n, kk;
int *arr, *sortedArr;
int cnt;
int result;

void merge(int start, int mid, int end) {
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            cnt++;
            if (cnt == kk) {
                result = arr[i];
            }
            sortedArr[k++] = arr[i++];
        } else {
            cnt++;
            if (cnt == kk) {
                result = arr[j];
            }
            sortedArr[k++] = arr[j++];
        }
    }
    if (i > mid) {
        for (int t = j; t <= end; t++) {
            cnt++;
            if (cnt == kk) {
                result = arr[t];
            }
            sortedArr[k++] = arr[t];
        }
    } else {
        for (int t = i; t <= mid; t++) {
            cnt++;
            if (cnt == kk) {
                result = arr[t];
            }
            sortedArr[k++] = arr[t];
        }
    }

    for (int t = start; t <= end; t++) {
        arr[t] = sortedArr[t];
    }
}

void mergeSort(int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        mergeSort(start, mid);
        mergeSort(mid + 1, end);
        merge(start, mid, end);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> kk;
    arr = new int[n];
    sortedArr = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    mergeSort(0, n - 1);

    cout << (result == 0 ? -1 : result) << "\n";
    return 0;
}