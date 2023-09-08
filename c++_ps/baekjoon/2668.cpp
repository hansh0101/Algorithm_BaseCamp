#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int n;
int arr[101];
set<int> result;

void getInput();
void solve();
void printResult();

void checkCycle(int);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();

    return 0;
}

void getInput() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
}

void checkCycle(int start) {
    queue<int> q;
    set<int> tempResult;
    bool visited[101] = {false};
    bool isCycle = false;

    q.push(start);
    visited[start] = true;
    tempResult.insert(start);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        int next = arr[cur];

        if (next == start) {
            isCycle = true;
        }

        if (!visited[next]) {
            q.push(next);
            visited[next] = true;
            tempResult.insert(next);
        }
    }

    if (isCycle) {
        for (auto i : tempResult) {
            result.insert(i);
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        checkCycle(i);
    }
}

void printResult() {
    cout << result.size() << "\n";
    for (int i : result) {
        cout << i << "\n";
    }
}