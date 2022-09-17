#include <iostream>
#include <vector>

using namespace std;

int t, n, d;
double median;
vector<pair<int, int>> calories;
int calorie;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        calories.clear();
        result = 0;
        median = 201;

        if (t == 2) {

        }

        cin >> n >> d;
        for (int i = 1; i <= n; i++) {
            // 1. 중앙값을 구한다.
            if (i > d) {
                int size = calories.size();
                if (calories.size() % 2 == 0) {
                    median = (double) (calories[size / 2 - 1].second + calories[size / 2].second) / 2;
                } else {
                    median = calories[size / 2].second;
                }
            }

            cin >> calorie;
            int index = calories.size();
            for (int j = 0; j < calories.size(); j++) {
                if (calorie < calories[j].second) {
                    index = j;
                    break;
                }
            }
            calories.insert(calories.begin() + index, {i, calorie});

            if (i > d) {
                if (calorie >= 2 * median) {
                    result++;
                }
                int target = -1;
                for (int j = 0; j < calories.size(); j++) {
                    if (calories[j].first == i - d) {
                        target = j;
                    }
                }
                calories.erase(calories.begin() + target);
            }
        }
        cout << result << "\n";
    }
    return 0;
}