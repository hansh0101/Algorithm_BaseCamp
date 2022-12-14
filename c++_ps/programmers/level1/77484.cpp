#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    vector<int> answer;
    set<int> lotto;
    for (int i = 0; i < lottos.size(); i++) {
        if (lottos[i] != 0) {
            lotto.insert(lottos[i]);
        }
    }

    set<int> win_num;
    for (int i = 0; i < win_nums.size(); i++) {
        win_num.insert(win_nums[i]);
    }

    int min = 0;
    int another = 0;
    for (auto i: lotto) {
        if (win_num.find(i) != win_num.end()) {
            min++;
        } else {
            another++;
        }
    }

    answer.push_back(another == 6 ? 6 : 7 - (6 - another));
    answer.push_back(min == 0 ? 6 : 7 - min);

    return answer;
}