#include <iostream>
using namespace std;

int t, x1, y1, x2, y2, n, cx, cy, r;
int result;

bool isInRange(int x, int y, int xx, int yy, int r) {
    return (x - xx) * (x - xx) + (y - yy) * (y - yy) <= r * r;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        result = 0;
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> cx >> cy >> r;
            if (isInRange(x1, y1, cx, cy, r) ^ (isInRange(x2, y2, cx, cy, r))) {
                result++;
            }
        }
        cout << result << "\n";
    }
}