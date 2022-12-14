#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum {
    north = 0, west = 1, south = 2, east = 3
};

int n, k, row, col, l, x;
char c;
int board[100][100];

int result;

int mr[4] = {-1, 0, 1, 0};
int mc[4] = {0, -1, 0, 1};

bool snake[100][100];
int direction;
int hr, hc;
int tr, tc;
vector<pair<int, char>> v;
queue<int> q;

bool move() {
    hr += mr[direction];
    hc += mc[direction];

    if (hr < 0 || hc < 0 || hr >= n || hc >= n) {
        return false;
    }

    if (snake[hr][hc]) {
        return false;
    }

    snake[hr][hc] = true;
    q.push(direction);
    if (board[hr][hc] == 1) {
        board[hr][hc] = 0;
    } else {
        int tDirection = q.front();
        q.pop();

        snake[tr][tc] = false;
        tr += mr[tDirection];
        tc += mc[tDirection];
    }

    return true;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> row >> col;
        board[row-1][col-1] = 1;
    }

    snake[0][0] = true;
    hr = hc = tr = tc = 0;
    direction = east;

    cin>>l;
    for (int i = 0; i < l; i++) {
        cin >> x >> c;
        v.push_back({x, c});
    }

    for (int i = 0; i < v.size(); i++) {
        int time = v[i].first;
        char dir = v[i].second;

        for (result; result < time; result++) {
            if (!move()) {
                cout << ++result;
                return 0;
            }
        }

        if (dir == 'L') {
            direction = (direction + 1) % 4;
        } else if (dir == 'D') {
            if(direction == 0) {
                direction = 3;
            } else {
                direction -= 1;
            }
        }
    }

    while(true) {
        if(!move()) {
            cout<<++result;
            return 0;
        }
        result++;
    }
}