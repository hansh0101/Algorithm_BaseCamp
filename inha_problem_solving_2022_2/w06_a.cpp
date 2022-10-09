#include <iostream>
#include <stack>

using namespace std;

int T, N, K;
int cnt;
stack<int> result;
stack<int> st[3];

void init() {
    cnt = 0;
    for (int i = 0; i < 3; i++) {
        while (!st[i].empty()) {
            st[i].pop();
        }
    }
    while (!result.empty()) {
        result.pop();
    }
}

void solution(int n, int from, int by, int to) {
    if (n == 1) {
        st[to].push(st[from].top());
        st[from].pop();
        cnt++;
        if (cnt == K) {
            result = st[1];
        }
    } else {
        solution(n - 1, from, to, by);
        st[to].push(st[from].top());
        st[from].pop();
        cnt++;
        if (cnt == K) {
            result = st[1];
        }
        solution(n - 1, by, from, to);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        init();
        cin >> N >> K;
        for (int i = N; i >= 1; i--) {
            st[0].push(i);
        }
        solution(N, 0, 1, 2);
        if (result.empty()) {
            cout << 0 << "\n";
        } else {
            while (!result.empty()) {
                cout << result.top() << " ";
                result.pop();
            }
            cout << "\n";
        }
    }
    return 0;
}