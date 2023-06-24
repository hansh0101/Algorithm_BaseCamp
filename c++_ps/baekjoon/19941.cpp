#include <iostream>
#include <cstring>

using namespace std;

int n, k;
string input;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    cin >> input;

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == 'P') {
            for (int j = i - k; j <= i + k; j++) {
                if (j < 0 || j >= input.length()) {
                    continue;
                }

                if (input[j] == 'H') {
                    input[j] = ' ';
                    result++;
                    break;
                }
            }
        }
    }

    cout << result << "\n";
    return 0;
}