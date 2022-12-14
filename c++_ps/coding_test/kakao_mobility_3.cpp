#include <string>
#include <vector>
#include <cmath>

using namespace std;

int toInt(string str) {
    int result = 0;
    int digits = pow(10, str.length() - 1);
    for (int i = 0; i < str.length(); i++) {
        result += digits * (str[i] - '0');
        digits /= 10;
    }
    return result;
}

vector<int> split(const string s, char c) {
    vector<int> result;

    int index = 0;
    for (int i = 0; i <= s.length(); i++) {
        if (i == s.length()) {
            result.push_back(toInt(s.substr(index, i - index)));
        } else {
            if (s[i] == c) {
                result.push_back(toInt(s.substr(index, i - index)));
                index = i + 1;
            }
        }
    }

    return result;
}

vector<int> addTimes(const vector<int> lastTime, const vector<int> delayedTime) {
    vector<int> result = lastTime;
    for (int i = 0; i < 4; i++) {
        result[2 + i] += delayedTime[i];
    }

    // second
    while (result[5] >= 60) {
        result[4] += 1;
        result[5] -= 60;
    }
    // minute
    while (result[4] >= 60) {
        result[3] += 1;
        result[4] -= 60;
    }
    // hour
    while (result[3] >= 24) {
        result[2] += 1;
        result[3] -= 24;
    }
    // day
    while (result[2] > 30) {
        result[1] += 1;
        result[2] -= 30;
    }
    // month
    while (result[1] > 12) {
        result[0] += 1;
        result[1] -= 12;
    }

    return result;
}

int calculateDiff(const vector<int> startTime, const vector<int> finishTime) {
    int startDay = (startTime[0] - 1) * 360 + (startTime[1] - 1) * 30 + startTime[2];
    int finishDay = (finishTime[0] - 1) * 360 + (finishTime[1] - 1) * 30 + finishTime[2];

    return finishDay - startDay;
}

vector<int> solution(string s, vector<string> times) {
    vector<int> answer;
    int isSuccess = 1; // answer[0]
    int days = 0; // answer[1]
    vector<vector<int>> saveTimes = vector<vector<int>>();

    // [0]: year, [1]: month, [2]: day, [3]: hour, [4]: minute, [5]: second
    vector<int> startTime = split(s, ':');
    saveTimes.push_back(startTime);

    for (int i = 0; i < times.size(); i++) {
        vector<int> delayedTime = split(times[i], ':');
        vector<int> currentTime = addTimes(saveTimes.back(), delayedTime);
        saveTimes.push_back(currentTime);
    }

    for (int i = 0; i < saveTimes.size() - 1; i++) {
        int diff = calculateDiff(saveTimes[i], saveTimes[i + 1]);
        if (diff > 1) {
            isSuccess = 0;
            break;
        }
    }

    vector<int> finishTime = saveTimes.back();
    days = calculateDiff(startTime, finishTime) + 1;

    answer.push_back(isSuccess);
    answer.push_back(days);
    return answer;
}

int main() {
    string s = "2021:04:12:16:08:35";
    vector<string> times = vector<string>();
    times.push_back("01:06:30:00");
    times.push_back("01:01:12:00");
    times.push_back("00:00:09:25");
    vector<int> result = solution(s, times);
//    cout << result[0] << ", " << result[1] << "\n";
}

/*
2021:04:12:16:08:35
01:06:30:00
01:04:12:00

2021:04:12:16:08:35
01:06:30:00
00:01:12:00

2021:04:12:16:10:42
01:06:30:00

2021:04:12:16:08:35
01:06:30:00
01:01:12:00
00:00:09:25
 */