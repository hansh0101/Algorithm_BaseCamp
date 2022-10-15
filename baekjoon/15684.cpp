#include <iostream>

using namespace std;

int N, M, H;
int a, b;
bool arr[11][31];
int result = 4;

bool check() {
    for (int i = 1; i <= N; i++) {
        int cur = i;
        for (int j = 1; j <= H; j++) {
            if (arr[cur][j]) cur++;
            else if (arr[cur - 1][j]) cur--;
        }
        if (cur != i) {
            return false;
        }
    }
    return true;
}

void recursion(int index, int count) {
    if (count >= 4) {
        return;
    }
    if (check()) {
        result = min(result, count);
        return;
    }

    for (int j = 1; j <= N - 1; j++) {
        for (int i = index; i <= H; i++) {
            if (arr[j][i] || arr[j - 1][i] || arr[j + 1][i]) {
                continue;
            }
            arr[j][i] = true;
            recursion(i, count + 1);
            arr[j][i] = false;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M >> H;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        arr[b][a] = true;
    }

    recursion(1, 0);
    if (result == 4) cout << "-1\n";
    else cout << result << "\n";
}