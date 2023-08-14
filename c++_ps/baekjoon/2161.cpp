#include <iostream>
#include <queue>

using namespace std;

int n;
queue<int> q;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    while (q.size() != 1) {
        int drop = q.front();
        q.pop();

        cout << drop << " ";
        int insert = q.front();
        q.pop();
        q.push(insert);
    }

    cout << q.front() << "\n";
    return 0;
}