#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<string> split(string s, char c) {
    vector<string> vec;

    int index = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (i == s.length()) {
            vec.push_back(s.substr(index, i - index));
        } else {
            if (s[i] == c) {
                vec.push_back(s.substr(index, i - index));
                index = i + 1;
            }
        }
    }

    return vec;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    vector<string> todayVector = split(today, '.');
    int todayYear = stoi(todayVector[0]);
    int todayMonth = stoi(todayVector[1]);
    int todayDay = stoi(todayVector[2]);

    map<char, int> termMap;
    for (string term: terms) {
        vector<string> termVector = split(term, ' ');
        char type = termVector[0][0];
        int due = stoi(termVector[1]);
        termMap[type] = due;
    }

    for (int i = 1; i <= privacies.size(); i++) {
        string privacy = privacies[i - 1];
        vector<string> privacyVector = split(privacy, ' ');
        string date = privacyVector[0];
        char type = privacyVector[1][0];

        vector<string> dateVector = split(date, '.');
        int year = stoi(dateVector[0]);
        int month = stoi(dateVector[1]);
        int day = stoi(dateVector[2]);

        int due = termMap[type];
        month += due;
        while (month > 12) {
            month -= 12;
            year++;
        }
        if (day == 1) {
            if (month == 1) {
                year--;
                month = 12;
            } else {
                month--;
            }
            day = 28;
        } else {
            day--;
        }

        cout << "today\n";
        cout << todayYear << "." << todayMonth << "." << todayDay << "\n";
        cout << "day\n";
        cout << year << "." << month << "." << day << "\n";

        if (year < todayYear) {
            answer.push_back(i);
        } else if (year == todayYear) {
            if (month < todayMonth) {
                answer.push_back(i);
            } else if (month == todayMonth) {
                if (day < todayDay) {
                    answer.push_back(i);
                }
            }
        }
    }

    return answer;
}