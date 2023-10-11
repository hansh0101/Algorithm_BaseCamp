#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;

    map<string, int> dict;
    for (vector<string> info : clothes) {
        dict[info[1]]++;
    }

    for (auto iter = dict.begin(); iter != dict.end(); iter++) {
        answer *= iter->second + 1;
    }

    return answer - 1;
}