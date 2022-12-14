#include <iostream>
#include <cstring>
using namespace std;

int t, n, m, q, u, v, w;
int result[250][250];

void init() {
    memset(result, 0, sizeof(result));
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        init();

        cin >> n >> m >> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i][j] = 1e9;
            }
            result[i][i] = 0;
        }
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            result[u][v] = result[v][u] = w;
        }

        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
                }
            }
        }

        for (int i = 0; i < q; i++) {
            cin >> u >> v;
            cout << result[u][v] << "\n";
        }
    }
}