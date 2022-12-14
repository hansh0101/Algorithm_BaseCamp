#include <iostream>

#include <string>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

vector<string> split(string s, char c) {
    vector<string> result;

    int index = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (i == s.length()) {
            result.push_back(s.substr(index, i - index));
        } else {
            if (s[i] == c) {
                result.push_back(s.substr(index, i - index));
                index = i + 1;
            }
        }
    }

    return result;
}

int solution(vector<string> id_list, int k) {
    int answer = 0;

    set<string> received[1000];
    unordered_map<string, int> couponCount;

    for (int i = 0; i < id_list.size(); i++) {
        vector<string> ids = split(id_list[i], ' ');
        for (string id: ids) {
            if (received[i].find(id) == received[i].end() && couponCount[id] < k) {
                couponCount[id]++;
                received[i].insert(id);
                answer++;
            }
        }
    }

    return answer;
}

int main() {
    vector<string> id_list = vector<string>();
    id_list.push_back("JAY");
    id_list.push_back("JAY ELLE JAY MAY");
    id_list.push_back("MAY ELLE MAY");
    id_list.push_back("ELLE MAY");
    id_list.push_back("ELLE ELLE ELLE");
    id_list.push_back("MAY");
    cout << solution(id_list, 3);
}