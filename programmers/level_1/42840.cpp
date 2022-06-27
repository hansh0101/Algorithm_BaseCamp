#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;

    int answer1[5] = {1, 2, 3, 4, 5};
    int answer2[8] = {2, 1, 2, 3, 2, 4, 2, 5};
    int answer3[10] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    int score1 = 0;
    int score2 = 0;
    int score3 = 0;

    for (int i = 0; i < answers.size(); i++) {
        if (answers[i] == answer1[index1]) {
            score1++;
        }
        if (answers[i] == answer2[index2]) {
            score2++;
        }
        if (answers[i] == answer3[index3]) {
            score3++;
        }

        index1++;
        index2++;
        index3++;
        index1 %= 5;
        index2 %= 8;
        index3 %= 10;
    }

    vector<pair<int, int>> result;
    result.push_back({-score1, 1});
    result.push_back({-score2, 2});
    result.push_back({-score3, 3});
    sort(result.begin(), result.end());

    int max = result[0].first;
    for (int i = 0; i < result.size(); i++) {
        if (result[i].first == max) {
            answer.push_back(result[i].second);
        }
    }

    return answer;
}