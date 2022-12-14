#include <iostream>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

int t, m, n, d;
priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<>> minHeap;
map<int, int> hashMap;
string cmd, opt;

void clear() {
    while (!maxHeap.empty()) maxHeap.pop();
    while (!minHeap.empty()) minHeap.pop();
    hashMap.clear();
}

void add() {
    maxHeap.push(d);
    minHeap.push(d);
    if (hashMap.find(d) != hashMap.end()) {
        hashMap[d]++;
    } else {
        hashMap[d] = 1;
    }
}

void remove() {
    if (opt == "max") {
        int value = maxHeap.top();
        maxHeap.pop();

        if (--hashMap[value] == 0) {
            hashMap.erase(value);
        }
    } else if (opt == "min") {
        int value = minHeap.top();
        minHeap.pop();

        if (--hashMap[value] == 0) {
            hashMap.erase(value);
        }
    }

    while (!maxHeap.empty()) {
        int value = maxHeap.top();
        if (hashMap.find(value) != hashMap.end()) {
            break;
        } else {
            maxHeap.pop();
        }
    }

    while (!minHeap.empty()) {
        int value = minHeap.top();
        if (hashMap.find(value) != hashMap.end()) {
            break;
        } else {
            minHeap.pop();
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        clear();

        cin >> m >> n;
        for (int i = 0; i < m; i++) {
            cin >> d;
            add();
        }

        for (int i = 0; i < n; i++) {
            cin >> cmd;
            if (cmd == "Add") {
                cin >> d;
                add();
            } else if (cmd == "Delete") {
                cin >> opt;
                remove();
            }
        }

        cout << minHeap.top() << " " << maxHeap.top() << "\n";
    }
    return 0;
}