#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int t, n, m, a, b, c;
vector<pair<int, int>> sharks;
vector<int> aquariums;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int result;

void init() {
    sharks.clear();
    aquariums.clear();
    while (!pq.empty()) {
        pq.pop();
    }
    result = 0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            sharks.push_back({a, b});
        }
        for (int i = 0; i < m; i++) {
            cin >> c;
            aquariums.push_back(c);
        }

        sort(sharks.begin(), sharks.end());
        sort(aquariums.begin(), aquariums.end());

        int index = 0;
        for (int i = 0; i < aquariums.size(); i++) {
            while (index < sharks.size() && sharks[index].first <= aquariums[i]) {
                pq.push({sharks[index].second, sharks[index].first});
                index++;
            }
            while (!pq.empty() && pq.top().first < aquariums[i]) {
                pq.pop();
            }
            if (!pq.empty()) {
                pq.pop();
                result++;
            }
        }

        cout << result << "\n";
    }
}