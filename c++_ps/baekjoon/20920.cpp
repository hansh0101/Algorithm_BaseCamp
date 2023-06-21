#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
string word;
map<string, int> wordCount;

bool comp(const pair<string, int>& a, const pair<string, int>& b) {
    if (a.second == b.second) {
        // 단어 출현 빈도가 같다면
        if (a.first.length() == b.first.length()) {
            // 단어 길이가 같다면 단어를 사전 순으로(오름차순)
            return a.first < b.first;
        }
        // 단어 길이가 다르다면 단어 길이를 내림차순으로
        return a.first.length() > b.first.length();
    }

    // 단어 출현 빈도가 다르다면 출현 빈도를 내림차순으로
    return a.second > b.second;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> word;

        if (word.length() >= m) {
            wordCount[word]++;
        }
    }

    vector<pair<string, int>> v(wordCount.begin(), wordCount.end());
    sort(v.begin(), v.end(), comp);

    for (pair<string, int> p : v) {
        cout << p.first << "\n";
    }

    return 0;
}