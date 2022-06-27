#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    string str;
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c - '0' >= 0 && c - '0' <= '9' - '0') {
            str += c;
        } else {
            if (c == 'z') {
                i += 3;
                str += '0';
            } else if (c == 'o') {
                i += 2;
                str += '1';
            } else if (c == 't') {
                if (s[i + 1] == 'w') {
                    i += 2;
                    str += '2';
                } else if (s[i + 1] == 'h') {
                    i += 4;
                    str += '3';
                }
            } else if (c == 'f') {
                if (s[i + 1] == 'o') {
                    i += 3;
                    str += '4';
                } else if (s[i + 1] == 'i') {
                    i += 3;
                    str += '5';
                }
            } else if (c == 's') {
                if (s[i + 1] == 'i') {
                    i += 2;
                    str += '6';
                } else if (s[i + 1] == 'e') {
                    i += 4;
                    str += '7';
                }
            } else if (c == 'e') {
                i += 4;
                str += '8';
            } else if (c == 'n') {
                i += 3;
                str += '9';
            }
        }
    }
    answer = stoi(str);

    return answer;
}