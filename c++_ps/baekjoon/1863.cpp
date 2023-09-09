#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
int x, y;
struct Point {
    int x;
    int y;

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
vector<Point> vec;
stack<int> st;
int result;

void getInput();
void solve();
void printResult();

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    getInput();
    solve();
    printResult();

    return 0;
}

void getInput() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        vec.push_back(Point(x, y));
    }
}

void solve() {
    vec.push_back(Point(x + 1, 0));

    for (Point p : vec) {
        while (!st.empty() && st.top() >= p.y) {
            if (st.top() > p.y) {
                result++;
            }
            st.pop();
        }

        st.push(p.y);
    }
}

void printResult() {
    cout << result << "\n";
}