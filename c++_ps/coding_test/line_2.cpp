#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;

string solution(int n, vector<string> dic, string chat) {
    string answer = "";

    vector<string> v;
    int index = 0;
    for (int i = 0; i <= chat.length(); i++) {
        if (i == chat.length()) {
            v.push_back(chat.substr(index, i - index));
        } else {
            if (chat[i] == ' ') {
                v.push_back(chat.substr(index, i - index));
                index = i + 1;
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        string userWord = v[i];
        bool result = false; // true면 비속어 아님

        for (int j = 0; j < dic.size(); j++) {
            string word = dic[j];
            result = false;

            cout << "userWord: " << userWord << " || word: " << word << "\n";

            if (userWord.length() > word.length()) {
                result = true;
                continue;
            }
            int replaceChance = 0;
            int replaceCount = 0;
            for (int k = 0; k < word.length(); k++) {
                int wordIndex = k - replaceCount;
                if (userWord[wordIndex] == word[k]) {
                    cout << "같습니다\n";
                    continue;
                }
                if (userWord[wordIndex] == '.') {
                    replaceChance += n - 1;
                    cout << ".을 교체했습니다\n";
                } else if (userWord[wordIndex] != word[k]) {
                    if (replaceChance == 0) {
                        cout << ".을 더 이상 활용할 수 없습니다\n";
                        result = true;
                        break;
                    } else {
                        cout << ".을 교체했습니다\n";
                        replaceChance--;
                        replaceCount++;
                    }
                }
            }
            if (!result) {
                break;
            }
        }
        if (result) {
            if (i == v.size() - 1) {
                answer += userWord;
            } else {
                answer += userWord + " ";
            }
        } else {
            string str = "";
            for (int j = 0; j < userWord.length(); j++) {
                str += "#";
            }
            if (i == v.size() - 1) {
                answer += str;
            } else {
                answer += str + " ";
            }
        }
    }

    return answer;
}