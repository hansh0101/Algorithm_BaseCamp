#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;

    map<string, int> dict;

    // 1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
    for (int i = 0; i < 26; i++) {
        string str = "";
        str += (char)('A' + i);
        dict[str] = i + 1;
    }

    for (int i = 0; i < msg.size();) {
        // 2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
        string w = "";
        int idx = -1;
        bool isFinished = false;
        for (int j = i; j < msg.size(); j++) {
            w += msg[j];
            idx = j;

            if (dict.find(w) == dict.end()) {
                w.erase(--w.end());
                break;
            }

            if (j == msg.size() - 1) {
                isFinished = true;
            }
        }

        // 3. w에 해당하는 사전의 색인 번호를 출력하고, 입력에서 w를 제거한다.
        answer.push_back(dict[w]);

        // 4. 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
        dict[w + msg[idx]] = dict.size() + 1;

        // 5. 단계 2로 돌아간다.
        i = idx;
        if (isFinished) {
            break;
        }
    }

    return answer;
}