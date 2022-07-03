#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";

    pair<int, int> rt = {0, 0};
    pair<int, int> cf = {0, 0};
    pair<int, int> jm = {0, 0};
    pair<int, int> an = {0, 0};

    for (int i = 0; i < survey.size(); i++) {
        string s = survey[i];
        int choice = abs(choices[i] - 4);
        bool isLeft = choices[i] <= 4;

        if (s[0] == 'R') {
            if (isLeft) {
                rt.first += choice;
            } else {
                rt.second += choice;
            }
        } else if (s[0] == 'T') {
            if (isLeft) {
                rt.second += choice;
            } else {
                rt.first += choice;
            }
        } else if (s[0] == 'C') {
            if (isLeft) {
                cf.first += choice;
            } else {
                cf.second += choice;
            }
        } else if (s[0] == 'F') {
            if (isLeft) {
                cf.second += choice;
            } else {
                cf.first += choice;
            }
        } else if (s[0] == 'J') {
            if (isLeft) {
                jm.first += choice;
            } else {
                jm.second += choice;
            }
        } else if (s[0] == 'M') {
            if (isLeft) {
                jm.second += choice;
            } else {
                jm.first += choice;
            }
        } else if (s[0] == 'A') {
            if (isLeft) {
                an.first += choice;
            } else {
                an.second += choice;
            }
        } else if (s[0] == 'N') {
            if (isLeft) {
                an.second += choice;
            } else {
                an.first += choice;
            }
        }
    }

    if(rt.first >= rt.second) {
        answer += 'R';
    } else {
        answer += 'T';
    }

    if(cf.first >= cf.second) {
        answer += 'C';
    } else {
        answer += 'F';
    }

    if(jm.first >= jm.second) {
        answer += 'J';
    } else {
        answer += 'M';
    }

    if(an.first >= an.second) {
        answer += 'A';
    } else {
        answer += 'N';
    }

    return answer;
}