#include <iostream>

using namespace std;

int n, m, h;
int a, b;
bool arr[31][11];
int result = 4;

bool check() {
    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int j = 1; j <= h; j++) {
            if (arr[j][cur]) cur++;
            else if (arr[j][cur - 1]) cur--;
        }
        if (cur != i) return false;
    }
    return true;
}

void recursion(int curDepth, int row) {
    if (check()) {
        result = min(result, curDepth);
        return;
    }
    if (curDepth == 3) return;

    for (int i = row; i <= h; i++) {
        for (int j = 1; j <= n - 1; j++) {
            if (arr[i][j] || arr[i][j - 1] || arr[i][j + 1]) continue;
            arr[i][j] = true;
            recursion(curDepth + 1, i);
            arr[i][j] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        arr[a][b] = true;
    }

    recursion(0, 1);
    cout << (result == 4 ? -1 : result) << "\n";
    return 0;
}