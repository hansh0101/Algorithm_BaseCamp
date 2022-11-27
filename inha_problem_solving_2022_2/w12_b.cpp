#include <iostream>
#include <vector>
#include <map>
#define pii pair<int, int>
using namespace std;

int t, n, cap;

vector<int> vec;
vector<int> result;
map<int, int> m;

void init();
void input();
void solve();
void print();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> t;
	while (t--) {
		init();
		input();
		solve();
		print();
	}
}

void init() {
	vec.clear();
	result.clear();
	m.clear();
}

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> cap;
		vec.push_back(cap);
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		int c = vec[i];
		int f = i + 1;

		if (m[c] != 0) {
			result.push_back(m[c]);
			m[c] = f;
		}
		else {
			m[c] = f;
			if (m.begin()->second == f) {
				result.push_back(-1);
			}
			else {
				result.push_back((--m.find(c))->second);
			}
		}
	}
}

void print() {
	for (int i : result) {
		cout << i << " ";
	}
	cout << "\n";
}

/*
2
5
20 40 10 20 30
5
1 1 1000 1 1
*/

/*
set을 사용한 풀이
*/
//#include <iostream>
//#include <set>
//#define pii pair<int, int>
//using namespace std;
//
//int t, n, cap;
//set<pii> s;
//int result;
//
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	cin >> t;
//	while (t--) {
//		// init
//		s.clear();
//
//		cin >> n;
//		for (int i = 0; i < n; i++) {
//			cin >> cap;
//
//			s.insert({ cap, i + 1 });
//			if (s.begin()->first == cap && s.begin()->second == i + 1) {
//				result = -1;
//			}
//			else {
//				result = (--s.find({ cap, i + 1 }))->second;
//			}
//
//			cout << result << " ";
//		}
//		cout << "\n";
//	}
//}