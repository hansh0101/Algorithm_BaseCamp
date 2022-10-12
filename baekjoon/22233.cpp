#include <iostream>
#include <vector>
#include <cstring>
#include <unordered_set>

using namespace std;

int N, M;
string inputString;
string inputText;
unordered_set<string> s;

vector<string> stringTokenizer(string str, char c) {
    vector<string> vec;
    int index = 0;
    for (int i = 0; i <= str.length(); i++) {
        if (i == str.length() || str[i] == c) {
            vec.push_back(str.substr(index, i - index));
            index = i + 1;
        }
    }
    return vec;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> inputString;
        s.insert(inputString);
    }
    for (int i = 0; i < M; i++) {
        cin >> inputText;
        vector<string> vec = stringTokenizer(inputText, ',');
        int count = 0;
        for (int j = 0; j < vec.size(); j++) {
            s.erase(vec[j]);
        }
        cout << s.size() - count << "\n";
    }
    return 0;
}