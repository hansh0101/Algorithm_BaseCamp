#include <iostream>
#include <vector>

using namespace std;

int n, input, p;
vector<int> scores;
int score;
int curScoreRank;
int curScoreCount;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> input >> p;
    for (int i = 0; i < n; i++) {
        cin >> score;
        scores.push_back(score);

        if (scores[i] == input) {
            curScoreCount++;
        }

        if (scores[i] < input && curScoreRank == 0) {
            curScoreRank = i + 1;
        }
    }

    if (curScoreRank == 0) {
        curScoreRank = scores.size() + 1;
    }

    if (curScoreRank > p) {
        cout << "-1\n";
    } else {
        cout << curScoreRank - curScoreCount << "\n";
    }

    return 0;
}