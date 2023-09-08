#include <iostream>
#include <cstring>
#define MAX 100001

using namespace std;

int n;
string input;
string output;
int result = MAX;

void getInput();
void solve();
void printResult();

char toggle(char c);
string toggle(string str, int index);

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();

    return 0;
}

void getInput() {
    cin >> n;
    cin >> input;
    cin >> output;
}

char toggle(char c) {
    if (c == '0') {
        return '1';
    }
    return '0';
}

string toggle(string str, int index)  {
    if (index == 0) {
        str[index] = toggle(str[index]);
        str[index + 1] = toggle(str[index + 1]);
    } else if (index == str.length() - 1) {
        str[index - 1] = toggle(str[index - 1]);
        str[index] = toggle(str[index]);
    } else {
        str[index - 1] = toggle(str[index - 1]);
        str[index] = toggle(str[index]);
        str[index + 1] = toggle(str[index + 1]);
    }

    return str;
}

void solve() {
    // 1. 0번 스위치를 누른 경우
    string str1 = input;
    int count1 = 0;

    str1 = toggle(str1, 0);
    count1++;
    
    for (int i = 1; i < str1.length(); i++) {
        if (str1[i - 1] != output[i - 1]) {
            str1 = toggle(str1, i);
            count1++;
        }
    }

    if (str1 == output) {
        result = min(result, count1);
    }

    // 2. 0번 스위치를 누르지 않은 경우
    string str2 = input;
    int count2 = 0;

    for (int i = 1; i < str2.length(); i++) {
        if (str2[i - 1] != output[i - 1]) {
            str2 = toggle(str2, i);
            count2++;
        }
    }

    if (str2 == output) {
        result = min(result, count2);
    }

    if (result == MAX) {
        result = -1;
    }
}

void printResult() {
    cout << result << "\n";
}