#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int e, s, m;
    cin >> e >> s >> m;

    int result = 1;
    while (e != 1 || s != 1 || m != 1) {
        e--;
        s--;
        m--;

        if (e == 0) {
            e = 15;
        }
        if (s == 0) {
            s = 28;
        }
        if (m == 0) {
            m = 19;
        }

        result++;
    }

    cout << result << "\n";
    return 0;
}