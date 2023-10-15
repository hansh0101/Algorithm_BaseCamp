#include <string>
#include <vector>
#include <set>
#include <algorithm>

#include <iostream>

using namespace std;

bool compare(vector<int> v1, vector<int> v2) {
    return v1.size() < v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;

    int stridx = 0;
    vector<string> strvec;
    
    s.erase(s.begin());
    s.erase(s.end() - 1);
    
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '{') {
            stridx = i;
        } else if (s[i] == '}') {
            strvec.push_back(s.substr(stridx + 1, i - stridx - 1));
        }
    }

    vector<vector<int>> vec;
    for (int i = 0; i < strvec.size(); i++) {
        vector<int> v;
        string str = strvec[i];
        int idx = 0;
        for (int j = 0; j <= str.length(); j++) {
            if (j == str.length() || str[j] == ',') {
                int num = stoi(str.substr(idx, j - idx));
                v.push_back(num);
                idx = j + 1;
            }
        }
        vec.push_back(v);
    }

    sort(vec.begin(), vec.end(), compare);
    set<int> st;

    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            if (st.find(vec[i][j]) == st.end()) {
                answer.push_back(vec[i][j]);
                st.insert(vec[i][j]);
            }
        }
    }

    return answer;
}