#include <iostream>
#include <queue>

using namespace std;

int n, num, m = 10001;
priority_queue<int> l;
priority_queue<int, vector<int>, greater<int>> r;

void solution(int number) {
    if (m == 10001) {
        m = number;
    } else {
        number > m ? r.push(number) : l.push(number);
        if (l.size() != r.size() && l.size() != r.size() - 1) {
            if (l.size() < r.size()) {
                l.push(m);
                m = r.top();
                r.pop();
            } else if (l.size() > r.size()) {
                r.push(m);
                m = l.top();
                l.pop();
            }
        }
    }

    cout << m << "\n";
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        solution(num);
    }

    return 0;
}