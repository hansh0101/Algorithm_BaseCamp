#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }

    int count = 1;
    vector<int> v;
    while (!q.empty()) {
        if (count == k) {
            v.push_back(q.front());
            q.pop();
            count = 1;
            continue;
        }
        int temp = q.front();
        q.pop();
        q.push(temp);
        count++;
    }

    cout << "<";
    for (int i = 0; i < v.size(); i++) {
        if (i == v.size() - 1) {
            cout << v[i] << ">";
        } else {
            cout << v[i] << ", ";
        }
    }

    return 0;
}