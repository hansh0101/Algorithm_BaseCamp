#include <iostream>
#include <queue>
#include <set>

using namespace std;

int arr[5][5];
set<string> s;
int mr[4] = {0, 0, 1, -1};
int mc[4] = {1, -1, 0, 0};

struct Element {
    int r;
    int c;
    string str;

    Element(int r, int c, string str) {
        this->r = r;
        this->c = c;
        this->str = str;
    }
};

void bfs(int r, int c) {
    queue<Element> q;
    q.push(Element(r, c, to_string(arr[r][c])));

    while (!q.empty()) {
        Element elem = q.front();
        q.pop();

        if (elem.str.length() == 6) {
            s.insert(elem.str);
            continue;
        }

        for (int i = 0; i < 4; i++) {
            int nr = elem.r + mr[i];
            int nc = elem.c + mc[i];

            if (nr < 0 || nr >= 5 || nc < 0 || nc >= 5) {
                continue;
            }

            q.push(Element(nr, nc, elem.str + to_string(arr[nr][nc])));
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            bfs(i, j);
        }
    }

    cout << s.size() << "\n";
    return 0;
}