#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int t, n, k;
vector<int> w;
vector<int> v;
vector<pair<int, int>> vec;
int result;

void init() {
	result = 0;
	w.clear();
	v.clear();
	vec.clear();
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		init();

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int weight;
			cin >> weight;
			w.push_back(weight);
		}
		for (int i = 0; i < n; i++) {
			int value;
			cin >> value;
			v.push_back(value);
			vec.push_back({ v[i] / w[i] , w[i]});
		}

		sort(vec.begin(), vec.end());
		for (int i = vec.size() - 1; i >= 0; i--) {
			int price = vec[i].first;
			int weight = vec[i].second;

			if (k == 0) {
				break;
			}

			if (k >= weight) {
				k -= weight;
				result += price * weight;
			}
			else {
				result += price * k;
				k = 0;
			}
		}
		cout << result << "\n";
	}
}

/*
2
7 95
36 14 48 32 61 43 29
36 56 240 320 61 43 290
6 73
26 71 6 37 12 15
234 639 54 111 96 150
*/