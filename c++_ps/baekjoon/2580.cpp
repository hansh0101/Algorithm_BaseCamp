#include <iostream>
#include <set>

using namespace std;

int board[9][9];
int answer[9][9];
set<pair<int, int>> holes;
set<int> rowCheck[9];
set<int> colCheck[9];
set<int> boxCheck[9];
bool isFinish;

void init();

void input();

void solve();

void print();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    init();
    input();
    solve();
    print();

    return 0;
}

void init() {
    for (int i = 0; i < 9; i++) {
        for (int j = 1; j <= 9; j++) {
            rowCheck[i].insert(j);
            colCheck[i].insert(j);
            boxCheck[i].insert(j);
        }
    }
}

void input() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cin >> board[r][c];
            if (board[r][c] == 0) {
                holes.insert({r, c});
            } else {
                rowCheck[r].erase(board[r][c]);
                colCheck[c].erase(board[r][c]);
                boxCheck[3 * (r / 3) + (c / 3)].erase(board[r][c]);
            }
        }
    }
}

void solve() {
    if (isFinish) {
        return;
    }

    if (holes.empty()) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                answer[r][c] = board[r][c];
            }
        }
        isFinish = true;
        return;
    }

    pair<int, int> p = *holes.begin();
    int r = p.first;
    int c = p.second;
    int boxIndex = 3 * (r / 3) + (c / 3);
    set<int> candidates;

    for (auto i: rowCheck[r]) {
        if (colCheck[c].find(i) != colCheck[c].end() && boxCheck[boxIndex].find(i) != boxCheck[boxIndex].end()) {
            candidates.insert(i);
        }
    }

    if (candidates.size() >= 2) {
        for (auto i: candidates) {
            board[r][c] = i;
            holes.erase({r, c});
            rowCheck[r].erase(i);
            colCheck[c].erase(i);
            boxCheck[boxIndex].erase(i);
            solve();
            boxCheck[boxIndex].insert(i);
            colCheck[c].insert(i);
            rowCheck[r].insert(i);
            holes.insert({r, c});
            board[r][c] = i;
        }
    } else if (candidates.size() == 1) {
        int i = *candidates.begin();
        board[r][c] = i;
        holes.erase({r, c});
        rowCheck[r].erase(i);
        colCheck[c].erase(i);
        boxCheck[boxIndex].erase(i);
        solve();
        boxCheck[boxIndex].insert(i);
        colCheck[c].insert(i);
        rowCheck[r].insert(i);
        holes.insert({r, c});
        board[r][c] = i;
    }
}

void print() {
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            cout << answer[r][c] << " ";
        }
        cout << "\n";
    }
}