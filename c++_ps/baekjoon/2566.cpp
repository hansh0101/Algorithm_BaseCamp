#include <iostream>
using namespace std;

int arr[9][9];
int r, c, m;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> arr[i][j];
            if (arr[i][j] > m) {
                r = i;
                c = j;
                m = arr[i][j];
            }
        }
    }

    cout << m << "\n" << r + 1 << " " << c + 1 << "\n";
    return 0;
}