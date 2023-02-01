#include <iostream>
#include <vector>
using namespace std;

int t, a, b;
string arr[11] = {"1110111", "0010010", "1011101", "1011011", "0111010",
                  "1101011", "1101111", "1110010", "1111111", "1111011", "0000000"};
vector<string> v[2];
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        result = 0;
        for (int i = 0; i < 2; i++) {
            v[i].clear();
        }

        cin >> a >> b;
        for (int i = 0; i < 5; i++) {
            if (a == 0) {
                v[0].push_back(arr[10]);
            } else {
                v[0].push_back(arr[a % 10]);
                a /= 10;
            }
        }
        for (int i = 0; i < 5; i++) {
            if (b == 0) {
                v[1].push_back(arr[10]);
            } else {
                v[1].push_back(arr[b % 10]);
                b /= 10;
            }
        }

        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 7; j++) {
                if (v[0][i][j] != v[1][i][j]) {
                    result++;
                }
            }
        }

        cout << result << "\n";
    }
    return 0;
}