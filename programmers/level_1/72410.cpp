#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = new_id;

    // 1. 대문자 -> 소문자
    string tmpAns = "";
    for (int i = 0; i < new_id.length(); i++) {
        char c = answer[i];
        if (c - 'A' >= 0 && c - 'A' <= 'Z' - 'A') {
            c = c + 'a' - 'A';
        }
        tmpAns += c;
    }
    answer = tmpAns;

    // 2. 소문자, 숫자, -, _, . 제외 모든 문자 제거
    tmpAns = "";
    for (int i = 0; i < answer.length(); i++) {
        char c = answer[i];
        if ((c - 'a' >= 0 && c - 'a' <= 'z' - 'a') || (c == '-') || (c == '_') || (c == '.') ||
            (c - '0' >= 0 && c - '0' <= '9' - '0')) {
            tmpAns += c;
        }
    }
    answer = tmpAns;

    // 3. 마침표가 연속 2번이면 하나의 마침표로 치환
    tmpAns = "";
    bool flag = false;
    for (int i = 0; i < answer.length(); i++) {
        char c = answer[i];
        if (c == '.') {
            if (!flag) {
                flag = true;
                tmpAns += c;
            }
        } else {
            flag = false;
            tmpAns += c;
        }
    }
    answer = tmpAns;

    // 4. 마침표가 처음이나 끝에 위치한다면 제거
    tmpAns = "";
    for (int i = 0; i < answer.length(); i++) {
        char c = answer[i];
        if (i == 0) {
            if (c != '.') {
                tmpAns += c;
            }
        } else if (i == answer.length() - 1) {
            if (c != '.') {
                tmpAns += c;
            }
        } else {
            tmpAns += c;
        }
    }
    answer = tmpAns;
    cout << "step 4. " << answer << "\n";

    // 5. 빈 문자열이라면 a 대입
    if (answer.length() == 0) {
        answer = "a";
    }

    // 6. 길이가 16자 이상이면 첫 15문자만, 마지막이 .이면 . 제거
    tmpAns = "";
    if (answer.length() >= 16) {
        for (int i = 0; i < 15; i++) {
            char c = answer[i];
            if (i != 14 || c != '.') {
                tmpAns += c;
            }
        }
    }
    if (tmpAns != "") {
        answer = tmpAns;
    }

    // 7. 2자 이하라면 길이가 3 될 때까지 마지막 글자를 계속 이어 붙임
    if (answer.length() <= 2) {
        while (answer.length() < 3) {
            answer += answer[answer.length() - 1];
        }
    }

    return answer;
}