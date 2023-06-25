#include <iostream>
#include <cstring>

using namespace std;

int n;
string input;
int arr[26];
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> input;
    for (char c : input) {
        arr[c - 'A']++;
    }

    for (int i = 1; i < n; i++) {
        int array[26];
        memset(array, 0, sizeof(array));

        string str;
        cin >> str;
        for (char c : str) {
            array[c - 'A']++;
        }
        
        int diff = 0;
        for (int j = 0; j < 26; j++) {
            diff += abs(arr[j] - array[j]);
        }
        if (input.length() == str.length()) {
            if (diff == 0 || diff == 2) {
                result++;
            }
        } else {
            if (diff == 1) {
                result++;
            }
        }
    }

    cout << result << "\n";
    return 0;
}