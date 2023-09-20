#include <string>
#include <iostream>
using namespace std;

bool solution(string s) {
    bool answer = true;
    int pCount = 0;
    int yCount = 0;
    
    for (char c : s) {
        if (c == 'P' || c == 'p') {
            pCount++;
        } else if (c == 'Y' || c == 'y') {
            yCount++;
        }
    }
    
    answer = pCount == yCount;

    return answer;
}