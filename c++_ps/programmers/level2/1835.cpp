#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;

    string friends = "ACFJMNRT";
    do {
        bool check = true;
        for (string str: data) {
            int firstIndex = friends.find(str[0]);
            int secondIndex = friends.find(str[2]);
            char oper = str[3];
            int distance = str[4] - '0';

            int diff = (int) (abs(firstIndex - secondIndex)) - 1;
            if (oper == '>') {
                if (diff > distance) continue;
                check = false;
                break;
            } else if (oper == '=') {
                if (diff == distance) continue;
                check = false;
                break;
            } else if (oper == '<') {
                if (diff < distance) continue;
                check = false;
                break;
            }
        }
        if (check) answer++;
    } while (next_permutation(friends.begin(), friends.end()));

    return answer;
}