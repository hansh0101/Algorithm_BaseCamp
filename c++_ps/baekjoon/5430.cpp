#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;

    while (t--) {
        string cmd;
        cin >> cmd;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        deque<int> dq;
        int s = 1;
        for (int i = 1; i < arr.length() - 1; i++) {
            if (i == arr.length() - 2) {
                dq.push_back(stoi(arr.substr(s, i - s + 1)));
            }

            if (arr[i] == ',') {
                dq.push_back(stoi(arr.substr(s, i - s + 1)));
                s = i + 1;
            }
        }

        bool isReverse = false;
        bool isError = false;
        for (char c: cmd) {
            if (c == 'R') {
                isReverse = !isReverse;
            } else {
                if (dq.empty()) {
                    isError = true;
                    break;
                } else {
                    if (isReverse) {
                        dq.pop_back();
                    } else {
                        dq.pop_front();
                    }
                }
            }
        }

        if (isError) {
            cout << "error\n";
        } else {
            if (isReverse) {
                cout << "[";
                for (int i = dq.size() - 1; i >= 0; i--) {
                    cout << dq[i];
                    if (i != 0) {
                        cout << ",";
                    }
                }
                cout << "]\n";
            } else {
                cout << "[";
                for (int i = 0; i < dq.size(); i++) {
                    cout << dq[i];
                    if (i != dq.size() - 1) {
                        cout << ",";
                    }
                }
                cout << "]\n";
            }
        }
    }

    return 0;
}