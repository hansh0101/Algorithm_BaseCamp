#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int solution(int n, int k) {
    int answer = 0;

    string str = "";

    while (n != 0) {
        str += to_string(n % k);
        n /= k;
    }
    reverse(str.begin(), str.end());

    string substr = "";
    vector<long long> vec;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '0' && substr != "") {
            vec.push_back(stoll(substr));
            substr = "";
        } else {
            substr += str[i];
        }
    }
    if (substr != "") {
        vec.push_back(stoll(substr));
    }

    for (int i = 0; i < vec.size(); i++) {
        long long num = vec[i];

        bool result = true;

        if (num == 0 || num == 1) {
            continue;
        }

        for (long long j = 2; j <= (long long)sqrt(num); j++) {
            if (num % j == 0) {
                result = false;
                break;
            }
        }

        if (result) {
            answer++;
        }
    }

    return answer;
}