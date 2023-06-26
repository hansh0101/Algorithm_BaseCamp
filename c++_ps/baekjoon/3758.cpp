#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int T;
int n, k, t, m;
int teamId, questionNumber, score;

int scores[100][100]; // i : teamId, j : questionId
int submitCount[100]; // i : teamId
int lastSubmitTime[100]; // i : teamId

vector<pair<pair<int, int>, pair<int, int>>> vec; // first.first : totalScore, first.second : submitCount, second.first : lastSubmitTime, second.second : teamId

int toIndex(int number) {
    return number - 1;
}

bool compare(pair<pair<int, int>, pair<int, int>> p1, pair<pair<int, int>, pair<int, int>> p2) {
    if (p1.first.first != p2.first.first) {
        return p1.first.first > p2.first.first;
    }

    if (p1.first.second != p2.first.second) {
        return p1.first.second < p2.first.second;
    }

    return p1.second.first < p2.second.first;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> T;
    while (T--) {
        memset(scores, 0, sizeof(scores));
        memset(submitCount, 0, sizeof(submitCount));
        memset(lastSubmitTime, 0, sizeof(lastSubmitTime));
        vec.clear();

        cin >> n >> k >> t >> m;

        for (int i = 0; i < m; i++) {
            cin >> teamId >> questionNumber >> score;

            scores[toIndex(teamId)][toIndex(questionNumber)] = max(scores[toIndex(teamId)][toIndex(questionNumber)], score);
            submitCount[toIndex(teamId)]++;
            lastSubmitTime[toIndex(teamId)] = i;
        }

        for (int i = 0; i < n; i++) {
            int totalScore = 0;
            for (int j = 0; j < k; j++) {
                totalScore += scores[i][j];
            }
            
            vec.push_back({{totalScore, submitCount[i]}, {lastSubmitTime[i], i + 1}});
        }

        sort(vec.begin(), vec.end(), compare);
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].second.second == t) {
                cout << i + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}