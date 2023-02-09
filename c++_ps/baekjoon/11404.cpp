#include <iostream>
#include <vector>

#define INF 1e9

using namespace std;

int n, m, a, b, c;
int nodes[101][101];
vector<pair<int, int>> edges[101];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                nodes[i][j] = 0;
            } else {
                nodes[i][j] = INF;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        nodes[a][b] = min(nodes[a][b], c);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {
                nodes[j][k] = min(nodes[j][k], nodes[j][i] + nodes[i][k]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (nodes[i][j] == 1e9) {
                cout << "0 ";
            } else {
                cout << nodes[i][j] << " ";
            }
        }
        cout << "\n";
    }
}