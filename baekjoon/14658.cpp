#include <iostream>
#include <vector>

using namespace std;

int N, M, L, K;
int x, y;
vector<pair<int, int>> stars;
int result;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M >> L >> K;
    for (int i = 0; i < K; i++) {
        cin >> x >> y;
        stars.emplace_back(x, y);
    }

    for (int i = 0; i < stars.size(); i++) {
        for (int j = 0; j < stars.size(); j++) {
            x = stars[i].first;
            y = stars[j].second;
            int count = 0;
            for (int k = 0; k < stars.size(); k++) {
                int curx = stars[k].first;
                int cury = stars[k].second;

                if (x <= curx && curx <= x + L && y <= cury && cury <= y + L) {
                    count++;
                }
            }
            result = max(result, count);
        }
    }

    cout << stars.size() - result << "\n";
    return 0;
}