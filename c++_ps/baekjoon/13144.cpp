#include <iostream>
#include <set>

using namespace std;

int n;
int arr[100000];
bool isContain[100001];
unsigned long long result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int start = 0;
    int end = 0;

    for (start = 0; start < n; start++) {
        while (end < n) {
            if (isContain[arr[end]]) {
                break;
            }
            isContain[arr[end]] = true;
            end++;
        }

        result += end - start;
        isContain[arr[start]] = false;
    }

    cout << result << "\n";
    return 0;
}