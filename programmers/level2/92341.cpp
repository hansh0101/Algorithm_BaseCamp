#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;

    int defaultTime, defaultPrice, defaultTerm, defaultPricePerTerm;
    defaultTime = fees[0];
    defaultPrice = fees[1];
    defaultTerm = fees[2];
    defaultPricePerTerm = fees[3];

    map<string, int> m;
    map<string, int> result;

    for (string record: records) {
        string strTime;
        string carNumber;
        string history;

        int index = 0;
        int count = 0;
        for (int i = 0; i <= record.length(); i++) {
            if (i == record.length()) {
                history = record.substr(index, i - index);
            } else {
                if (record[i] == ' ') {
                    if (count == 0) {
                        strTime = record.substr(index, i - index);
                    } else if (count == 1) {
                        carNumber = record.substr(index, i - index);
                    }
                    index = i + 1;
                    count++;
                }
            }
        }

        string strHour, strMinute;
        strHour = strTime.substr(0, 2);
        strMinute = strTime.substr(3, 2);

        int time = stoi(strHour) * 60 + stoi(strMinute);

        if (history == "IN") {
            m[carNumber] = time;
        } else if (history == "OUT") {
            if (result.find(carNumber) == result.end()) {
                result[carNumber] = time - m[carNumber];
            } else {
                result[carNumber] += time - m[carNumber];
            }
            m.erase(carNumber);
        }
    }

    int closeTime = 23 * 60 + 59;
    for (auto iter: m) {
        string carNumber = iter.first;
        int inTime = iter.second;
        if (result.find(carNumber) == result.end()) {
            result[carNumber] = closeTime - inTime;
        } else {
            result[carNumber] += closeTime - inTime;
        }
    }

    vector<pair<string, int>> v;

    for (auto iter: result) {
        string carNumber = iter.first;
        int time = iter.second;

        int price = 0;
        if (time >= defaultTime) {
            price += defaultPrice;
            time -= defaultTime;
        } else {
            time = 0;
            price += defaultPrice;
        }
        if (time != 0) {
            if (time % defaultTerm != 0) {
                price += defaultPricePerTerm * (time / defaultTerm + 1);
            } else {
                price += defaultPricePerTerm * (time / defaultTerm);
            }
        }

        v.push_back({carNumber, price});
    }

    sort(v.begin(), v.end());
    for (auto i: v) {
        answer.push_back(i.second);
    }

    return answer;
}