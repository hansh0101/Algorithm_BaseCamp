#include <iostream>
#include <vector>

using namespace std;

int N, num, result;
vector<vector<int>> initBoard;
int mr[4] = {-1, 0, 1, 0};
int mc[4] = {0, -1, 0, 1};

vector<vector<int>> zipUp(vector<vector<int>> board) {
    vector<int> vec[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) {
                vec[j].push_back(board[i][j]);
            }
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i >= vec[j].size()) {
                board[i][j] = 0;
            } else {
                board[i][j] = vec[j][i];
            }
        }
    }

    return board;
}

vector<vector<int>> moveUp(vector<vector<int>> board) {
    board = zipUp(board);
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == board[i + 1][j]) {
                board[i][j] *= 2;
                board[i + 1][j] = 0;
            }
        }
    }
    board = zipUp(board);
    return board;
}

vector<vector<int>> zipLeft(vector<vector<int>> board) {
    vector<int> vec[N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] != 0) {
                vec[i].push_back(board[i][j]);
            }
            board[i][j] = 0;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j >= vec[i].size()) {
                board[i][j] = 0;
            } else {
                board[i][j] = vec[i][j];
            }
        }
    }

    return board;
}

vector<vector<int>> moveLeft(vector<vector<int>> board) {
    board = zipLeft(board);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (board[i][j] == board[i][j + 1]) {
                board[i][j] *= 2;
                board[i][j + 1] = 0;
            }
        }
    }
    board = zipLeft(board);
    return board;
}

vector<vector<int>> zipDown(vector<vector<int>> board) {
    vector<int> vec[N];
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (board[i][j] != 0) {
                vec[j].push_back(board[i][j]);
            }
            board[i][j] = 0;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (N - 1 - i >= vec[j].size()) {
                board[i][j] = 0;
            } else {
                board[i][j] = vec[j][N - 1 - i];
            }
        }
    }

    return board;
}

vector<vector<int>> moveDown(vector<vector<int>> board) {
    board = zipDown(board);
    for (int i = N - 1; i >= 1; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (board[i][j] == board[i - 1][j]) {
                board[i][j] *= 2;
                board[i - 1][j] = 0;
            }
        }
    }
    board = zipDown(board);
    return board;
}

vector<vector<int>> zipRight(vector<vector<int>> board) {
    vector<int> vec[N];
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (board[i][j] != 0) {
                vec[i].push_back(board[i][j]);
            }
            board[i][j] = 0;
        }
    }

    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 0; j--) {
            if (N - 1 - j >= vec[i].size()) {
                board[i][j] = 0;
            } else {
                board[i][j] = vec[i][N - 1 - j];
            }
        }
    }

    return board;
}

vector<vector<int>> moveRight(vector<vector<int>> board) {
    board = zipRight(board);
    for (int i = N - 1; i >= 0; i--) {
        for (int j = N - 1; j >= 1; j--) {
            if (board[i][j] == board[i][j - 1]) {
                board[i][j] *= 2;
                board[i][j - 1] = 0;
            }
        }
    }
    board = zipRight(board);
    return board;
}

void recursion(vector<vector<int>> board, int count) {
    if (count == 5) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                result = max(result, board[i][j]);
            }
        }
        return;
    }

    vector<vector<int>> newBoard;
    newBoard = moveUp(board);
    recursion(newBoard, count + 1);
    newBoard = moveLeft(board);
    recursion(newBoard, count + 1);
    newBoard = moveDown(board);
    recursion(newBoard, count + 1);
    newBoard = moveRight(board);
    recursion(newBoard, count + 1);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    initBoard.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> num;
            initBoard[i][j] = num;
        }
    }

    recursion(initBoard, 0);
    cout << result << "\n";
    return 0;
}