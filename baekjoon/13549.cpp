#include <iostream>
#include <queue>

using namespace std;

int N, K;
queue<pair<int, int>> q;
bool visit[100001];
int result;

void solution() {
    while (!q.empty()) {
        int cur = q.front().first;
        int curTime = q.front().second;
        q.pop();

        if (cur == K) {
            result = curTime;
            break;
        }

        int cpyCur = cur;
        while (true) {
            cpyCur *= 2;
            if (cpyCur > 100000) {
                break;
            }
            if (!visit[cpyCur]) {
                q.push({cpyCur, curTime});
                visit[cpyCur] = true;
            } else {
                break;
            }
        }

        if (cur - 1 >= 0 && !visit[cur - 1]) {
            q.push({cur - 1, curTime + 1});
            visit[cur - 1] = true;
        }
        if (cur + 1 <= 100000 && !visit[cur + 1]) {
            q.push({cur + 1, curTime + 1});
            visit[cur + 1] = true;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> K;
    q.push({N, 0});
    visit[N] = true;
    solution();

    cout << result << "\n";
    return 0;
}