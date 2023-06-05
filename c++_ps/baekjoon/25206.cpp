#include <iostream>
#include <cstring>

using namespace std;

string subject;
double credit;
string grade;

double creditSum;
double gradeSum;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 20; i++) {
        cin >> subject >> credit >> grade;

        if (grade == "P") {
            continue;
        } else if (grade == "A+") {
            gradeSum += 4.5 * credit;
        } else if (grade == "A0") {
            gradeSum += 4.0 * credit;
        } else if (grade == "B+") {
            gradeSum += 3.5 * credit;
        } else if (grade == "B0") {
            gradeSum += 3.0 * credit;
        } else if (grade == "C+") {
            gradeSum += 2.5 * credit;
        } else if (grade == "C0") {
            gradeSum += 2.0 * credit;
        } else if (grade == "D+") {
            gradeSum += 1.5 * credit;
        } else if (grade == "D0") {
            gradeSum += 1.0 * credit;
        } else if (grade == "F") {
            gradeSum += 0 * credit;
        }
        creditSum += credit;
    }

    cout << gradeSum / creditSum << "\n";
    return 0;
}