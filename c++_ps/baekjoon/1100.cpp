#include <iostream>
#include <cstring>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    bool isWhite = true;
    string str;
    int answer = 0;
    for (int i = 0; i < 8; i++) {
        isWhite = !isWhite;
        cin >> str;
        for (char c: str) {
            isWhite = !isWhite;
            if (isWhite && c == 'F') {
                answer++;
            }
        }
    }

    cout << answer << "\n";
    return 0;
}