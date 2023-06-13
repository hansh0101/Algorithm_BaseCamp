#include <iostream>
#include <cstring>

using namespace std;

string input;

bool isVowel(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return true;
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true) {
        cin >> input;

        if (input == "end") {
            break;
        }

        // 1. 모음을 포함하는가 ?
        bool isContainVowels = false;
        for (int i = 0; i < input.length(); i++) {
            if (isVowel(input[i])) {
                isContainVowels = true;
                break;
            }
        }

        // 2. 모음이 3개 혹은 자음이 3개 연속으로 오는가 ?
        bool isTripleContinuousSameType = false;
        if (input.length() >= 3) {
            bool isOneBeforeCharVowel = isVowel(input[0]);
            bool isTwoBeforeCharVowel = isVowel(input[1]);

            for (int i = 2; i < input.length(); i++) {
                bool isCurrentCharVowel = isVowel(input[i]);

                if (isTwoBeforeCharVowel == isOneBeforeCharVowel && isOneBeforeCharVowel == isCurrentCharVowel) {
                    isTripleContinuousSameType = true;
                    break;
                }

                isTwoBeforeCharVowel = isOneBeforeCharVowel;
                isOneBeforeCharVowel = isCurrentCharVowel;
            }
        }

        // 3. 같은 글자가 연속으로 두 번 오는가 ?
        bool isDoubleContinuousSameChar = false;
        if (input.length() >= 2) {
            char beforeChar = input[0];

            for (int i = 1; i < input.length(); i++) {
                char currentChar = input[i];

                if (beforeChar == currentChar && (currentChar != 'e' && currentChar != 'o')) {
                    isDoubleContinuousSameChar = true;
                    break;
                }

                beforeChar = currentChar;
            }
        }

        bool isAcceptable = isContainVowels && !isTripleContinuousSameType && !isDoubleContinuousSameChar;
        if (isAcceptable) {
            cout << "<" << input << "> is acceptable.\n";
        } else {
            cout << "<" << input << "> is not acceptable.\n";
        }
    }

    return 0;
}