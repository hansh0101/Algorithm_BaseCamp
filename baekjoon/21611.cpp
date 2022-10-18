#include <iostream>
#include <vector>

using namespace std;

int N, M;
int d, s;
int R, C;
int arr[50][50];
vector<int> vec;
int mr[5] = {0, -1, 1, 0, 0};
int mc[5] = {0, 0, 0, -1, 1};
int count1, count2, count3;

void arrToVec() {
    int curr = R;
    int curc = C;
    int count = 1;
    while (true) {
        // 1. Move Left
        for (int i = 0; i < count; i++) {
            curc--;
            if (arr[curr][curc] != 0) {
                vec.push_back(arr[curr][curc]);
            }
            if (curr == 1 && curc == 1) {
                goto ARR_TO_VEC_OUT;
            }
        }
        // 2. Move Down
        for (int i = 0; i < count; i++) {
            curr++;
            if (arr[curr][curc] != 0) {
                vec.push_back(arr[curr][curc]);
            }
        }
        // 3. Move Right
        for (int i = 0; i < count + 1; i++) {
            curc++;
            if (arr[curr][curc] != 0) {
                vec.push_back(arr[curr][curc]);
            }
        }
        // 4. Move Up
        for (int i = 0; i < count + 1; i++) {
            curr--;
            if (arr[curr][curc] != 0) {
                vec.push_back(arr[curr][curc]);
            }
        }
        count += 2;
    }

    ARR_TO_VEC_OUT:
    ;
}

void deleteZeroFromVec() {
    vector<int> newVec;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] != 0) {
            newVec.push_back(vec[i]);
        }
    }
    vec = newVec;
}

void vecToArr() {
    int curr = R;
    int curc = C;
    int count = 1;
    int index = 0;
    while (true) {
        // 1. Fill Arr with Move Left
        for (int i = 0; i < count; i++) {
            curc--;
            if (index < vec.size()) {
                arr[curr][curc] = vec[index];
            } else {
                arr[curr][curc] = 0;
            }
            if (curr == 1 && curc == 1) {
                goto VEC_TO_ARR_OUT;
            }
            index++;
        }
        // 2. Fill Arr with Move Down
        for (int i = 0; i < count; i++) {
            curr++;
            if (index < vec.size()) {
                arr[curr][curc] = vec[index];
            } else {
                arr[curr][curc] = 0;
            }
            index++;
        }
        // 3. Fill Arr with Move Right
        for (int i = 0; i < count + 1; i++) {
            curc++;
            if (index < vec.size()) {
                arr[curr][curc] = vec[index];
            } else {
                arr[curr][curc] = 0;
            }
            index++;
        }
        // 4. Fill Arr with Move Up
        for (int i = 0; i < count + 1; i++) {
            curr--;
            if (index < vec.size()) {
                arr[curr][curc] = vec[index];
            } else {
                arr[curr][curc] = 0;
            }
            index++;
        }
        count += 2;
    }
    VEC_TO_ARR_OUT:
    vec.clear();
}

void transform() {
    vector<int> newVec;
    for (int i = 0; i < vec.size(); i++) {
        int count = 1;
        int number = vec[i];
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] == vec[j]) {
                count++;
            } else {
                break;
            }
        }
        newVec.push_back(count);
        newVec.push_back(number);
        i += count - 1;
    }
    vec = newVec;

    vecToArr();
}

void boom() {
    while (true) {
        bool loopCondition = true;
        for (int i = 0; i < vec.size(); i++) {
            int count = 1;
            for (int j = i + 1; j < vec.size(); j++) {
                if (vec[i] == vec[j]) {
                    count++;
                } else {
                    break;
                }
            }
            if (count >= 4) {
                loopCondition = false;
                if (vec[i] == 1) count1 += count;
                else if (vec[i] == 2) count2 += count;
                else if (vec[i] == 3) count3 += count;
                for (int j = i; j < i + count; j++) {
                    vec[j] = 0;
                }
            }
            if (count != 1) {
                i += count - 1;
            }
        }

        if (loopCondition) {
            break;
        }

        deleteZeroFromVec();
    }

    transform();
}

void blizzard() {
    int curr = R;
    int curc = C;
    for (int i = 1; i <= s; i++) {
        int nr = curr + mr[d] * i;
        int nc = curc + mc[d] * i;
        arr[nr][nc] = 0;
    }
    arrToVec();
    boom();
}

void solution() {
    blizzard();
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    R = (N + 1) / 2;
    C = (N + 1) / 2;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> arr[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> d >> s;
        solution();
    }

    cout << count1 + 2 * count2 + 3 * count3 << "\n";
    return 0;
}