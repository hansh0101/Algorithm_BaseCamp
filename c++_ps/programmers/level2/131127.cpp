#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;

    map<string, int> dict;
    for (int i = 0; i < want.size(); i++) {
        dict[want[i]] = i;
    }

    for (int i = 0; i < 10; i++) {
        if (dict.find(discount[i]) != dict.end()) {
            int index = dict[discount[i]];
            number[index]--;   
        }
    }

    bool isSatisfied = true;
    for (int i = 0; i < number.size(); i++) {
        if (number[i] != 0) {
            isSatisfied = false;
            break;
        }
    }

    if (isSatisfied) {
        answer++;
    }

    for (int i = 10; i < discount.size(); i++) {
        if (dict.find(discount[i - 10]) != dict.end()) {
            int index = dict[discount[i - 10]];
            number[index]++;
        }

        if (dict.find(discount[i]) != dict.end()) {
            int index = dict[discount[i]];
            number[index]--;
        }

        isSatisfied = true;
        for (int j = 0; j < number.size(); j++) {
            if (number[j] != 0) {
                isSatisfied = false;
                break;
            }
        }

        if (isSatisfied) {
            answer++;
        }
    }

    return answer;
}