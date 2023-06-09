#include <iostream>
using namespace std;

int h, w, n, m;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> h >> w >> n >> m;
    for (int i = 1; i <= h; i += n + 1) {
        for (int j = 1; j <= w; j+= m + 1) {
            result++;
        }
    }

    cout << result << "\n";
    return 0;
}