#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int T, N, K;
int discs[11];
int cnt;
stack<int> result;
stack<int> st[3];

void init() {
    memset(discs, 0, sizeof(discs));
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
        for (int i = 0; i < discs[1]; i++) {
            st[to].push(st[from].top());
            st[from].pop();
            cnt++;
            if (cnt == K) {
                result = st[1];
            }
        }
    } else {
        solution(n - 1, from, to, by);
        for (int i = 0; i < discs[n]; i++) {
            st[to].push(st[from].top());
            st[from].pop();
            cnt++;
            if (cnt == K) {
                result = st[1];
            }
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
        cin >> N;
        for (int i = 1 ; i <= N; i++) {
            cin >> discs[i];
        }
        cin >> K;
        for (int i = N; i >= 1; i--) {
            for (int j = 0; j < discs[i]; j++) {
                st[0].push(i);
            }
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