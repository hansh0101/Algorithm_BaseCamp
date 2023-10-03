#include <iostream>

using namespace std;

int n, m, broken;
bool isBroken[10];
int result;

bool check(int ch) {
    if (ch == 0 && isBroken[0]) {
        return false;
    }

    while (ch != 0) {
        if (isBroken[ch % 10]) {
            return false;
        }
        
        ch /= 10;
    }

    return true;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> broken;
        isBroken[broken] = true;
    }

    result = abs(n - 100);

    for (int i = 0; i <= 999900; i++) {
        if (check(i)) {
            int cnt = abs(n - i) + to_string(i).length();
            result = min(result, cnt);
        }
    }

    cout << result << "\n";
    return 0;
}