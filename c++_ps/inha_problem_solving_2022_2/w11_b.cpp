#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, m, tn;
vector<int> prize;
vector<pair<int, int>> score;
vector<int> chance;
int rest, result;

void init() {
    prize.clear();
    score.clear();
    chance.clear();
    rest = result = 0;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> n >> m;
        score.resize(m, {0, 0});
        chance.resize(m, 0);

        for (int i = 0; i < n; i++) {
            cin >> tn;
            prize.push_back(tn);
            score[tn - 1].first += n - i;
            score[tn - 1].second = tn;
            if (i != 0 && tn == 1 && prize[i - 1] != 1) {
                chance[prize[i - 1] - 1]++;
                rest++;
            }
        }

        sort(score.begin(), score.end(), greater<pair<int, int>>());
        while (rest > 0) {
            if (score[0].second == 1 && score[0].first > score[1].first) {
                break;
            }
            bool flag = true;
            for (int i = 0; i < score.size(); i++) {
                if (score[i].second == 1) {
                    score[i].first++;
                }
                if (flag && chance[score[i].second - 1] > 0) {
                    flag = false;
                    chance[score[i].second - 1]--;
                    score[i].first--;
                    rest--;
                    result++;
                }
            }

            sort(score.begin(), score.end(), greater<pair<int, int>>());
        }

        if (score[0].second == 1 && score[0].first > score[1].first) {
            cout << result << "\n";
        } else {
            cout << "-1\n";
        }
    }
}