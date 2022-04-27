#include <iostream>

using namespace std;

int n, m, x, y, k;
int arr[20][20];
int result;

enum direction {
    RIGHT = 1, LEFT = 2, UP = 3, DOWN = 4
};

class Side {
public:
    Side *up;
    Side *down;
    Side *left;
    Side *right;
    Side *opposite;
    int value;

    Side() {
        up = down = left = right = opposite = nullptr;
        value = 0;
    }

    void setSide(Side *u, Side *d, Side *l, Side *r) {
        up = u;
        down = d;
        left = l;
        right = r;
    }
};

class Dice {
public:
    Side *one;
    Side *two;
    Side *three;
    Side *four;
    Side *five;
    Side *six;
    Side *top;

    Dice() {
        one = new Side();
        two = new Side();
        three = new Side();
        four = new Side();
        five = new Side();
        six = new Side();
        top = one;

        one->setSide(two, five, four, three);
        one->opposite = six;
        six->opposite = one;

        two->opposite = five;
        five->opposite = two;

        three->opposite = four;
        four->opposite = three;
    }

    void rollUp() {
        Side *nTop = top->down;
        nTop->up = top;
        nTop->left = top->left;
        nTop->right = top->right;
        nTop->down = top->opposite;
        top = nTop;
    }

    void rollDown() {
        Side *nTop = top->up;
        nTop->down = top;
        nTop->left = top->left;
        nTop->right = top->right;
        nTop->up = top->opposite;
        top = nTop;
    }

    void rollLeft() {
        Side *nTop = top->right;
        nTop->left = top;
        nTop->right = top->opposite;
        nTop->up = top->up;
        nTop->down = top->down;
        top = nTop;
    }

    void rollRight() {
        Side *nTop = top->left;
        nTop->right = top;
        nTop->left = top->opposite;
        nTop->up = top->up;
        nTop->down = top->down;
        top = nTop;
    }
};

bool isOut(int r, int c) {
    if (r < 0 || c < 0 || r >= n || c >= m) {
        return true;
    }
    return false;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> x >> y >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    Dice dice;
    int nx = x, ny = y;

    for (int i = 0; i < k; i++) {
        int direction;
        cin >> direction;

        if (direction == UP) {
            if (!isOut(nx - 1, ny)) {
                nx -= 1;
                ny = ny;
                dice.rollUp();
                if(arr[nx][ny] != 0) {
                    dice.top->opposite->value = arr[nx][ny];
                    arr[nx][ny] = 0;
                } else {
                    arr[nx][ny] = dice.top->opposite->value;
                }
                cout << dice.top->value << "\n";
            }
        } else if (direction == DOWN) {
            if (!isOut(nx + 1, ny)) {
                nx += 1;
                ny = ny;
                dice.rollDown();
                if(arr[nx][ny] != 0) {
                    dice.top->opposite->value = arr[nx][ny];
                    arr[nx][ny] = 0;
                } else {
                    arr[nx][ny] = dice.top->opposite->value;
                }
                cout << dice.top->value << "\n";
            }
        } else if (direction == LEFT) {
            if (!isOut(nx, ny - 1)) {
                nx = nx;
                ny -= 1;
                dice.rollLeft();
                if(arr[nx][ny] != 0) {
                    dice.top->opposite->value = arr[nx][ny];
                    arr[nx][ny] = 0;
                } else {
                    arr[nx][ny] = dice.top->opposite->value;
                }
                cout << dice.top->value << "\n";
            }
        } else if (direction == RIGHT) {
            if (!isOut(nx, ny + 1)) {
                nx = nx;
                ny += 1;
                dice.rollRight();
                if(arr[nx][ny] != 0) {
                    dice.top->opposite->value = arr[nx][ny];
                    arr[nx][ny] = 0;
                } else {
                    arr[nx][ny] = dice.top->opposite->value;
                }
                cout << dice.top->value << "\n";
            }
        }
    }

    return 0;
}