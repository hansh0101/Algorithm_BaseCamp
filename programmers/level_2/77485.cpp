#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int arr[100][100];

void init(int r, int c) {
    int n = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] = n;
            n++;
        }
    }
}

int rotate(int x1, int y1, int x2, int y2) {
    vector<int> v;

    int tmp = arr[x1][y1];
    for (int i = x1; i <= x2 - 1; i++) {
        arr[i][y1] = arr[i + 1][y1];
        v.push_back(arr[i][y1]);
    }

    for (int i = y1; i <= y2 - 1; i++) {
        arr[x2][i] = arr[x2][i + 1];
        v.push_back(arr[x2][i]);
    }

    for (int i = x2; i >= x1 + 1; i--) {
        arr[i][y2] = arr[i - 1][y2];
        v.push_back(arr[i][y2]);
    }

    for (int i = y2; i >= y1 + 1; i--) {
        if (i == y1 + 1) {
            arr[x1][i] = tmp;
        } else {
            arr[x1][i] = arr[x1][i - 1];
        }
        v.push_back(arr[x1][i]);
    }

    sort(v.begin(), v.end());
    return v[0];
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;

    init(rows, columns);

    for (int i = 0; i < queries.size(); i++) {
        vector<int> q = queries[i];
        answer.push_back(rotate(q[0] - 1, q[1] - 1, q[2] - 1, q[3] - 1));
    }

    return answer;
}