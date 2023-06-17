#include <iostream>
#include <vector>

using namespace std;

int switchCount;
vector<int> switches;
int status;
int studentCount;
int sex, number;

void toggle(int index) {
    if (switches[index] == 0) {
        switches[index] = 1;
    } else if (switches[index] == 1) {
        switches[index] = 0;
    }
}

void changeStatusByMale(int num) {
    for (int i = num - 1; i < switches.size(); i += num) {
        toggle(i);
    }
}

void changeStatusByFemale(int num) {
    int left = num - 1, right = num - 1;
    while (left >= 0 && right < switches.size()) {
        if (switches[left] != switches[right]) {
            break;
        }

        left--;
        right++;
    }

    for (int i = left + 1; i < right; i++) {
        toggle(i);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> switchCount;
    for (int i = 0; i < switchCount; i++) {
        cin >> status;
        switches.push_back(status);
    }

    cin >> studentCount;
    for (int i = 0; i < studentCount; i++) {
        cin >> sex >> number;

        if (sex == 1) {
            changeStatusByMale(number);
        } else if (sex == 2) {
            changeStatusByFemale(number);
        }
    }

    for (int i = 0; i < switches.size(); i++) {
        if (i % 20 == 0 && i != 0) {
            cout << "\n";
        }
        cout << switches[i] << " ";
    }
    
    return 0;
}