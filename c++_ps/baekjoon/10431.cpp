#include <iostream>
#include <cstring>

using namespace std;

int p, t, h;
int arr[20];
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> p;
    for (int i = 1; i <= p; i++) {
        memset(arr, 0, sizeof(arr));
        result = 0;

        cin >> t;
        for (int j = 0; j < 20; j++) {
            cin >> h;

            bool isInserted = false;
            for (int k = 0; k < j; k++) {
                if (arr[k] > h) {
                    for (int l = j; l >= k + 1; l--) {
                        arr[l] = arr[l - 1];
                        result++;
                    }
                    arr[k] = h;
                    isInserted = true;
                    break;
                }
            }

            if (!isInserted) {
                arr[j] = h;
            }
        }

        cout << t << " " << result << "\n";
    }

    return 0;
}