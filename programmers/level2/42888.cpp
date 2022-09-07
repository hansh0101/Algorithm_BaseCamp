#include <string>
#include <vector>
#include <map>
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

vector<string> solution(vector<string> record) {
    vector<string> answer;

    map<string, string> m;

    for (int i = 0; i < record.size(); i++) {
        vector<string> vec = split(record[i], ' ');

        if(vec[0] == "Enter") {
            string str = "";
            str += vec[1];
            str += " 들어왔습니다.";
            m[vec[1]] = vec[2];
            answer.push_back(str);
        } else if(vec[0] == "Leave") {
            string str = "";
            str += vec[1];
            str += " 나갔습니다.";
            answer.push_back(str);
        } else if(vec[0] == "Change") {
            m[vec[1]] = vec[2];
        }
    }

    for(int i=0; i<answer.size(); i++) {
        vector<string> vec = split(answer[i], ' ');
        answer[i] = m[vec[0]] + "님이 " + vec[1];
    }

    return answer;
}