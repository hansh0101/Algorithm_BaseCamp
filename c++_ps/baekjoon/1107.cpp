#include <iostream>
#include <cstring>

using namespace std;

int n, m;
bool isBroken[10];
int result = 1e9;

bool checkChannel(int ch) {
    bool res = true;

    while (ch != 0) {
        if (isBroken[ch % 10]) {
            res = false;
            break;
        }
        ch /= 10;
    }

    return res;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        isBroken[num] = true;
    }

    // 1. n보다 큰 채널로 이동 후 - 눌러서 채널 낮추기
    int ch = n;
    while (!checkChannel(ch)) {
        if (ch > 500000) {
            break;
        }
        ch++;
    }
    result = min((unsigned long)result, ch - n + to_string(ch).length());
    

    // 2. n보다 작은 채널로 이동 후 + 눌러서 채널 높이기
    ch = n;
    while (!checkChannel(ch)) {
        if (ch == 100 || ch == 0) {
            break;
        }
        ch--;
    }

    if (ch == 100) {
        result = min(result, n - ch);
    } else {
        result = min((unsigned long)result, n - ch + to_string(ch).length());
    }

    cout << result << "\n";
}