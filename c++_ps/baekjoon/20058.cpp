#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
using pii = pair<int, int>;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n_size = 1, l_size = 1;
int ice_count = 0;
bool vis[64][64];

void dfs(vector<vector<int>> &v, int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n_size || ny >= n_size) continue;
        if (vis[nx][ny] || v[nx][ny] <= 0) continue;
        vis[nx][ny] = 1;
        dfs(v, nx, ny);
        ice_count++;
    }
}

void map_rotation(vector<vector<int>> &v, int x, int y) {
    vector<vector<int>> tmp;
    for (int i = 0; i < l_size; i++) {
        vector<int> e(l_size);
        tmp.push_back(e);
    }
    int tmp_x = 0, tmp_y = 0;
    for (int i = y; i < y + l_size; i++) {
        for (int j = x + l_size - 1; j >= x; j--) {
            tmp[tmp_x][tmp_y] = v[j][i];
            tmp_y++;
        }
        tmp_x++;
        tmp_y = 0;
    }

    tmp_x = 0, tmp_y = 0;
    for (int i = x; i < x + l_size; i++) {
        for (int j = y; j < y + l_size; j++) {
            v[i][j] = tmp[tmp_x][tmp_y];
            tmp_y++;
        }
        tmp_x++;
        tmp_y = 0;
    }
}

void decrease_ice(vector<vector<int>> &v, vector<pii> &pos) {
    for (auto p: pos) {
        v[p.first][p.second]--;
    }
}

bool check_all_dir(vector<vector<int>> &v, int x, int y) {
    int count = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= n_size || ny >= n_size) continue;
        if (v[nx][ny] > 0) count++;
    }
    if (count >= 3) return true;
    else return false;
}

void divide_area(vector<vector<int>> &v) {
    for (int i = 0; i < n_size; i += l_size) {
        for (int j = 0; j < n_size; j += l_size) {
            map_rotation(v, i, j);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    n_size = pow(2, n);

    vector<vector<int>> v;
    for (int i = 0; i < n_size; i++) {
        vector<int> e(n_size);
        for (int j = 0; j < n_size; j++) {
            cin >> e[j];
        }
        v.push_back(e);
    }

    while (q--) {
        vector<pii> pos;
        int l;
        cin >> l;
        l_size = pow(2, l);
        divide_area(v);
        for (int i = 0; i < n_size; i++) {
            for (int j = 0; j < n_size; j++) {
                if (!check_all_dir(v, i, j)) pos.push_back({i, j});
            }
        }
        decrease_ice(v, pos);
        l_size = 1;
    }

    int sum = 0, answer = 0;

    for (int i = 0; i < n_size; i++) {
        for (int j = 0; j < n_size; j++) {
            if (v[i][j] > 0) sum += v[i][j];
            if (vis[i][j] || v[i][j] <= 0) continue;
            else {
                ice_count = 0;
                dfs(v, i, j);
                answer = answer < ice_count ? ice_count : answer;
            }
        }
    }
    cout << sum << "\n";
    cout << answer;

    return 0;
}