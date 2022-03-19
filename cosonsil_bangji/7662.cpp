#include <iostream>
#include <queue>
#include <map>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t, k;
    cin >> t;

    while (t--) {
        priority_queue<int> maxheap;
        priority_queue<int, vector<int>, greater<int>> minheap;
        map<int, int> map;

        cin >> k;
        for (int i = 0; i < k; i++) {
            char c;
            int n;
            cin >> c >> n;

            if (c == 'I') {
                // 삽입
                maxheap.push(n);
                minheap.push(n);
                if (map.find(n) != map.end()) {
                    map[n]++;
                } else {
                    map[n] = 1;
                }
            } else if (c == 'D') {
                if (map.empty()) continue;

                if (n == 1) {
                    // 최댓값 삭제
                    int max = maxheap.top();
                    maxheap.pop();

                    if (--map[max] == 0) {
                        map.erase(max);
                    }
                } else if (n == -1) {
                    // 최솟값 삭제
                    int min = minheap.top();
                    minheap.pop();

                    if (--map[min] == 0) {
                        map.erase(min);
                    }
                }


                while (!maxheap.empty()) {
                    // map에 없는 것들은 싹 삭제해준다
                    int max = maxheap.top();
                    if (map.find(max) != map.end()) {
                        // 있는 값이면 break;
                        break;
                    } else {
                        // 없는 값이면 pq에서 삭제
                        maxheap.pop();
                    }
                }

                while (!minheap.empty()) {
                    // map에 없는 것들은 싹 삭제해준다
                    int min = minheap.top();
                    if (map.find(min) != map.end()) {
                        // 있는 값이면 break;
                        break;
                    } else {
                        // 없는 값이면 pq에서 삭제
                        minheap.pop();
                    }
                }
            }
        }

        if (map.empty()) {
            cout << "EMPTY\n";
        } else {
            cout << maxheap.top() << " " << minheap.top() << "\n";
        }
    }
}