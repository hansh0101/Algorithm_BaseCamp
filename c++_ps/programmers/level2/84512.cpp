#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

set<string> s;

void makeCombination(int count, string str) {
    if (count == 5) {
        s.insert(str);
        return;
    }

    str += 'A';
    makeCombination(count + 1, str);
    str.pop_back();
    str += 'E';
    makeCombination(count + 1, str);
    str.pop_back();
    str += 'I';
    makeCombination(count + 1, str);
    str.pop_back();
    str += 'O';
    makeCombination(count + 1, str);
    str.pop_back();
    str += 'U';
    makeCombination(count + 1, str);
    str.pop_back();

    makeCombination(count + 1, str);
}

int solution(string word) {
    makeCombination(0, "");

    map<string, int> dict;
    int index = 0;
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        dict[*iter] = index;
        index++;
    }

    return dict[word];
}