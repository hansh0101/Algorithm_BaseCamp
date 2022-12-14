#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    int result = 0;
    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;

        if (dq.front() == num) {
            dq.pop_front();
            continue;
        }

        int move2 = 0;
        for (int j = 0; j < dq.size(); j++) {
            if (dq[j] == num) {
                move2 = j;
            }
        }
        int move3 = dq.size() - move2;

        if (move2 <= move3) {
            for (int j = 0; j < move2; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
            result += move2;
        } else {
            for (int j = 0; j < move3; j++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            result += move3;
        }
        dq.pop_front();
    }

    cout << result << "\n";
    return 0;
}