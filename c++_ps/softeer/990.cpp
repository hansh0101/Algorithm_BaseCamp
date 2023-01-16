#include <iostream>
#include <cstring>

using namespace std;

string startTimeStr, endTimeStr;
int startTime, endTime;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 5; i++) {
        cin >> startTimeStr >> endTimeStr;
        startTime = stoi(startTimeStr.substr(0, 2)) * 60 + stoi(startTimeStr.substr(3, 5));
        endTime = stoi(endTimeStr.substr(0, 2)) * 60 + stoi(endTimeStr.substr(3, 5));

        result += endTime - startTime;
    }

    cout << result << "\n";
    return 0;
}