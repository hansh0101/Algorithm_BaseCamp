#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    int loser = -1;
    int turn = 0;
    int index = 0;
    char startCharacter = ' ';
    set<string> dict;
    
    while (loser == -1) {
        if (index == words.size()) {
            break;
        }
        
        if (index % n == 0) {
            turn++;
        }
        
        string word = words[index];
        
        if (index != 0 && (dict.find(word) != dict.end() || word[0] != startCharacter)) {
            loser = index % n;
        } else {
            dict.insert(word);
            startCharacter = word[word.length() - 1];  
        }
        
        index++;
    }
    
    if (loser == -1) {
        answer.push_back(loser + 1);
        answer.push_back(0);
    } else {
        answer.push_back(loser + 1);
        answer.push_back(turn);
    }

    return answer;
}