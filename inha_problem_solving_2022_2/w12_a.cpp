#include <iostream>
#define ll long long
using namespace std;

int t, x, a, b;
int result;
ll tDist, bDist;
bool flag;

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
	result = 0;
	tDist = 0;
	bDist = 0;
	flag = false;
}

void input() {
	cin >> x >> a >> b;
}

void solve() {
	bDist += x;
	while (tDist < bDist) {
		tDist += 2 * a;
		bDist += a;

		if (tDist >= bDist) {
			flag = true;
			break;
		}
		bDist += b;
	};

	int runCount = 0;
	int restCount = 0;
	while (tDist != bDist) {
		if (flag) {
			flag = false;
			restCount = b;
		}

		if (runCount == a && restCount == b) {
			runCount = 0;
			restCount = 0;
		}

		if (restCount != b) {
			bDist--;
			restCount++;
			continue;
		}
		else {
			tDist -= 2;
			bDist--;
			runCount++;
			continue;
		}
	}
}

void print() {
	cout << bDist << "\n";
}

/*
5
30 10 3
28 10 3
60 18 3
77 15 9
188 18 11
*/

/*
시간이 더 오래 걸리는 방법
*/
//#include <iostream>
//using namespace std;
//
//int t, x, a, b;
//int tDist, bDist;
//
//int main() {
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
//
//	cin >> t;
//	while (t--) {
//		tDist = 0;
//		bDist = 0;
//
//		cin >> x >> a >> b;
//
//		bDist = x;
//		int runCount = 0;
//		int restCount = 0;
//		while (tDist != bDist) {
//			if (runCount == a && restCount == b) {
//				runCount = 0;
//				restCount = 0;
//			}
//
//			if (runCount != a) {
//				tDist += 2;
//				bDist += 1;
//				runCount++;
//			}
//			else {
//				bDist += 1;
//				restCount++;
//			}
//		}
//
//		cout << bDist << "\n";
//	}
//}