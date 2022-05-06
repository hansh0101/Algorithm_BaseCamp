#include <string>
#include <vector>
#include <cmath>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";

    pair<int, int> l = {3, 0};
    pair<int, int> r = {3, 2};

    for (int i = 0; i < numbers.size(); i++) {
        int num = numbers[i];
        if (num == 1 || num == 4 || num == 7) {
            answer += 'L';
            if (num == 1) {
                l = {0, 0};
            } else if (num == 4) {
                l = {1, 0};
            } else if (num == 7) {
                l = {2, 0};
            }
        } else if (num == 3 || num == 6 || num == 9) {
            answer += 'R';
            if (num == 3) {
                r = {0, 2};
            } else if (num == 6) {
                r = {1, 2};
            } else if (num == 9) {
                r = {2, 2};
            }
        } else if (num == 2 || num == 5 || num == 8 || num == 0) {
            if(num == 2) {
                pair<int, int> cur = {0, 1};
                int ldiff = abs(cur.first - l.first) + abs(cur.second - l.second);
                int rdiff = abs(cur.first - r.first) + abs(cur.second - r.second);
                if(ldiff < rdiff) {
                    answer += 'L';
                    l = cur;
                } else if(rdiff < ldiff) {
                    answer += 'R';
                    r = cur;
                } else {
                    if(hand == "right") {
                        answer += 'R';
                        r = cur;
                    } else {
                        answer += 'L';
                        l = cur;
                    }
                }
            } else if(num == 5) {
                pair<int, int> cur = {1, 1};
                int ldiff = abs(cur.first - l.first) + abs(cur.second - l.second);
                int rdiff = abs(cur.first - r.first) + abs(cur.second - r.second);
                if(ldiff < rdiff) {
                    answer += 'L';
                    l = cur;
                } else if(rdiff < ldiff) {
                    answer += 'R';
                    r = cur;
                } else {
                    if(hand == "right") {
                        answer += 'R';
                        r = cur;
                    } else {
                        answer += 'L';
                        l = cur;
                    }
                }
            } else if(num == 8) {
                pair<int, int> cur = {2, 1};
                int ldiff = abs(cur.first - l.first) + abs(cur.second - l.second);
                int rdiff = abs(cur.first - r.first) + abs(cur.second - r.second);
                if(ldiff < rdiff) {
                    answer += 'L';
                    l = cur;
                } else if(rdiff < ldiff) {
                    answer += 'R';
                    r = cur;
                } else {
                    if(hand == "right") {
                        answer += 'R';
                        r = cur;
                    } else {
                        answer += 'L';
                        l = cur;
                    }
                }
            } else if(num == 0) {
                pair<int, int> cur = {3, 1};
                int ldiff = abs(cur.first - l.first) + abs(cur.second - l.second);
                int rdiff = abs(cur.first - r.first) + abs(cur.second - r.second);
                if(ldiff < rdiff) {
                    answer += 'L';
                    l = cur;
                } else if(rdiff < ldiff) {
                    answer += 'R';
                    r = cur;
                } else {
                    if (hand == "right") {
                        answer += 'R';
                        r = cur;
                    } else {
                        answer += 'L';
                        l = cur;
                    }
                }
            }
        }
    }

    return answer;
}