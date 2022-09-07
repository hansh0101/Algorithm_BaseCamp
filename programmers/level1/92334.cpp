#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <sstream>

using namespace std;

vector<string> split(string str, char Delimiter) {
    istringstream iss(str);
    string buffer;

    vector<string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }

    return result;
}

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    vector<string> reportLog[1000];
    int reportedLog[1000];
    memset(reportedLog, 0, sizeof(reportedLog));
    vector<string> reportedUser;

    for (int i = 0; i < report.size(); i++) {
        vector<string> rv = split(report[i], ' ');
        string reporter = rv[0];
        string reported = rv[1];

        int reporterIdx = find(id_list.begin(), id_list.end(), reporter) - id_list.begin();
        int reportedIdx = find(id_list.begin(), id_list.end(), reported) - id_list.begin();
        if (find(reportLog[reporterIdx].begin(), reportLog[reporterIdx].end(), reported) ==
            reportLog[reporterIdx].end()) {
            reportLog[reporterIdx].push_back(reported);
            reportedLog[reportedIdx]++;
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        if (reportedLog[i] >= k) {
            reportedUser.push_back(id_list[i]);
        }
    }

    for (int i = 0; i < id_list.size(); i++) {
        int count = 0;
        for (int j = 0; j < reportedUser.size(); j++) {
            if (find(reportLog[i].begin(), reportLog[i].end(), reportedUser[j]) != reportLog[i].end()) {
                count++;
            }
        }
        answer.push_back(count);
    }

    return answer;
}