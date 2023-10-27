#include <iostream>

using namespace std;

int main() {
    long long answer = 0;
    int n;

    for (int i = 0; i < 5; i++) {
        cin >> n;
        answer += n;
    }

    cout << answer << "\n";
    return 0;
}