#include <iostream>

using namespace std;

int n, k;
int arr[200000];
int counter[100001];
int result;

void getInput() {
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void solve() {
    int startIndex = 0;
    for (int i = 0; i < n; i++) {
        counter[arr[i]]++;
        while (counter[arr[i]] > k) {
            counter[arr[startIndex]]--;
            startIndex++;
        }

        result = max(result, i + 1 - startIndex);
    }
}

void printResult() {
    cout << result << "\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();
}