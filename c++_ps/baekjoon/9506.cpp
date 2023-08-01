#include <iostream>
#include <vector>

using namespace std;

vector<int> getDivisors(int num) {
    vector<int> divisors;
    for (int i = 1; i < num; i++) {
        if (num % i == 0) {
            divisors.push_back(i);
        }
    }

    return divisors;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int num = 0;
    while (true) {
        cin >> num;
        if (num == -1) {
            break;
        }

        vector<int> divisors = getDivisors(num);
        int sum = 0;
        for (int i = 0; i < divisors.size(); i++) {
            sum += divisors[i];
        }

        if (sum == num) {
            cout << num;
            for (int i = 0; i < divisors.size(); i++) {
                if (i == 0) {
                    cout << " = ";
                } else {
                    cout << " + ";
                }
                cout << divisors[i];
            }
            cout << "\n";
        } else {
            cout << num << " is NOT perfect.\n";
        }
    }

    return 0;
}