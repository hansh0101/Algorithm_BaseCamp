#include <iostream>
using namespace std;

int n, r, c;
int arr[100][100];
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        cin >> r >> c;
        for (int i = r; i < r + 10; i++) {
            for (int j = c; j < c + 10; j++) {
                arr[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (arr[i][j] == 1) {
                result++;
            }
        }
    }

    cout << result << "\n";
    return 0;
}