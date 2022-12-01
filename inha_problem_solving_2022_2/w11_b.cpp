#include <iostream>
#include <cstring>
#include <algorithm>
#define pii pair<int, int>

using namespace std;

int t, n, m;
int team[100001]; // team[i]: person i's team number
pii score[100001]; // first: total score, second: team number
int chance[100001];
int rest, answer;

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
    memset(team, 0, sizeof(team));
    for (int i = 0; i < 100001; i++) {
        score[i] = {0, 0};
    }
    memset(chance, 0, sizeof(chance));
    rest = 0, answer = 0;
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> team[i];
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        score[team[i]].first += n - (i - 1);
        score[team[i]].second = team[i];
        if (i != 1 && team[i] == 1 && team[i - 1] != team[i]) {
            rest++;
            chance[team[i - 1]]++;
        }
    }

    sort(score + 1, score + m + 1);
    while (rest > 0) {
        if (score[m].second == 1 && score[m].first > score[m - 1].first) {
            break;
        }
        bool flag = true;
        for (int i = m; i >= 1; i--) {
            if (score[i].second == 1) {
                score[i].first++;
            }
            if (flag && chance[score[i].second] > 0) {
                chance[score[i].second]--;
                score[i].first--;
                flag = false;
                rest--;
                answer++;
            }
        }
        sort(score + 1, score + m + 1);
    }
}

void print() {
    if (score[m].second == 1 && score[m].first > score[m - 1].first) {
        cout << answer << "\n";
    } else {
        cout << "-1\n";
    }
}