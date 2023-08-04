#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int minX = 10001, minY = 10001, maxX = -10001, maxY = -10001;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        minX = min(minX, x);
        minY = min(minY, y);
        maxX = max(maxX, x);
        maxY = max(maxY, y);
    }

    cout << (maxX - minX) * (maxY - minY) << "\n";
}