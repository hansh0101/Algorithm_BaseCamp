#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(string s) {
    int answer = 100000;

    for (int i = 1; i <= s.length() + 1 / 2; i++) {
        string mstr = "";
        string str = s.substr(0, i);
        int count = 1;
        bool flag = false;
        for (int j = i; j < s.length() + 1; j += i) {
            string sstr = s.substr(j, i);
            if (str == sstr) {
                flag = true;
                count++;
            } else {
                flag = false;
                if (count == 1) {
                    mstr += str;
                } else {
                    mstr += to_string(count);
                    mstr += str;
                }
                count = 1;
                str = sstr;
            }
        }

        if (flag) {
            mstr += to_string(count);
            mstr += str;
        } else {
            mstr += str;
        }

        answer = min(answer, (int) mstr.length());
    }

    return answer;
}