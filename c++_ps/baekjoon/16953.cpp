#include <iostream>
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;

    queue<pair<long long, int>> q;
    q.push({a, 1});

    int result = -1;

    while (!q.empty()) {
        long long cur = q.front().first;
        int curCnt = q.front().second;
        q.pop();

        if (cur == b) {
            result = curCnt;
            break;
        }
        if (cur > b) {
            continue;
        }

        if (2 * cur <= b) {
            q.push({2 * cur, curCnt + 1});
        }
        if (10 * cur + 1 <= b) {
            q.push({10 * cur + 1, curCnt + 1});
        }
    }

    cout << result << "\n";

    return 0;
}