#include <iostream>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    map<int, string> m1;
    map<string, int> m2;
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        m1[i] = name;
        m2[name] = i;
    }

    for (int i = 0; i < m; i++) {
        string str;
        cin >> str;

        bool isString = false;
        for (char c: str) {
            if (c - '0' >= 0 && c - '0' <= 9) {
                continue;
            } else {
                isString = true;
                break;
            }
        }

        if (!isString) {
            int num = stoi(str);
            cout << m1[num] << "\n";
        } else {
            cout << m2[str] << "\n";
        }
    }

    return 0;
}