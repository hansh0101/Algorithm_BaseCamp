#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int t, n, m;
pii sharks[100000];
int aquariums[100000];
priority_queue<pii, vector<pii>, greater<pii>> pq;
int answer;

void init();
void input();
void solve();
void print();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();
        input();
        solve();
        print();
    }
}

void init() {
    for (int i = 0; i < 100000; i++) {
        sharks[i] = {0, 0};
        aquariums[i] = 0;
    }
    while (!pq.empty()) {
        pq.pop();
    }
    answer = 0;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> sharks[i].first >> sharks[i].second;
    }
    for (int i = 0; i < m; i++) {
        cin >> aquariums[i];
    }
}

void solve() {
    sort(sharks, sharks + n);
    sort(aquariums, aquariums + m);
    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j < n && sharks[j].first <= aquariums[i]) {
            pq.push({sharks[j].second, sharks[j].first});
            j++;
        }
        while(!pq.empty() && pq.top().first < aquariums[i]) {
            pq.pop();
        }
        if (!pq.empty()) {
            pq.pop();
            answer++;
        }
    }
}

void print() {
    cout << answer << "\n";
}