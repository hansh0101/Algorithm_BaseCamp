#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int scoreDiff = 0;
vector<int> ans(11);

int check(vector<int> info, vector<int> answer) {
    int aScore = 0;
    int lScore = 0;
    for (int i = 0; i <= 10; i++) {
        if (info[i] == 0 && answer[i] == 0) continue;
        if (info[i] >= answer[i]) aScore += i;
        else lScore += i;
    }
    return lScore - aScore;
}

void recursion(int score, int chance, vector<int> info, vector<int> answer) {
    if (score == -1 || chance == 0) {
        if (chance != 0) answer[0] = chance;
        int result = check(info, answer);
        if (result > 0 && result >= scoreDiff) {
            if (result == scoreDiff) {
                for (int i = 0; i <= 10; i++) {
                    if (answer[i] > ans[i]) {
                        ans = answer;
                        break;
                    } else if (answer[i] < ans[i]) {
                        break;
                    }
                }
            } else {
                ans = answer;
                scoreDiff = result;
            }
        }
    } else {
        // (가능하면) 라이언이 이기게 만들기
        if (info[score] < chance) {
            answer[score] = info[score] + 1;
            chance -= answer[score];
            recursion(score - 1, chance, info, answer);
            chance += answer[score];
            answer[score] = 0;
        }
        // 라이언이 지게 만들기
        recursion(score - 1, chance, info, answer);
    }
}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer(11, 0);

    int chance = n;
    reverse(info.begin(), info.end());
    recursion(10, chance, info, answer);
    answer = ans;
    reverse(answer.begin(), answer.end());

    int sum = 0;
    for (int i: answer) {
        sum += i;
    }

    if (sum == 0) {
        return vector<int>(1, -1);
    } else {
        return answer;
    }
}