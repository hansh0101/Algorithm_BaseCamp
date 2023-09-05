#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int t;
string w;
int k;
vector<int> vec[26];
int answer3, answer4;

void initialize();
void getInput();
void solve();
void printResult();

int toIndex(char);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        initialize();
        getInput();
        solve();
        printResult();
    }

    return 0;
}

void initialize() {
    for (int i = 0; i < 26; i++) {
        vec[i].clear();
    }
    answer3 = 10001;
    answer4 = -1;
}

void getInput() {
    cin >> w;
    cin >> k;
}

void solve() {
    for (int i = 0; i < w.length(); i++) {
        char c = w[i];
        vec[toIndex(c)].push_back(i);

        // 3. 어떤 문자를 정확히 K개를 포함하는 가장 짧은 연속 문자열의 길이 구하기
        if (vec[toIndex(c)].size() >= k) {
            int vecSize = vec[toIndex(c)].size();
            int lastIndex = vec[toIndex(c)][vecSize - 1];
            int firstIndex = vec[toIndex(c)][vecSize - k];
            answer3 = min(answer3, lastIndex - firstIndex + 1);
        }

        // 4. 어떤 문자를 정확히 K개를 포함하고, 문자열의 첫 번째와 마지막 글자가 해당 문자로 같은 가장 긴 연속 문자열의 길이 구하기
        if (vec[toIndex(c)].size() >= k) {
            int vecSize = vec[toIndex(c)].size();
            int lastIndex = vec[toIndex(c)][vecSize - 1];
            int firstIndex = vec[toIndex(c)][vecSize - k];
            answer4 = max(answer4, lastIndex - firstIndex + 1);
        }
    }
}

void printResult() {
    if (answer3 == 10001 || answer4 == -1) {
        cout << "-1\n";
    } else {
        cout << answer3 << " " << answer4 << "\n";
    }
}

int toIndex(char c) {
    return (int)(c - 'a');
}