#include <iostream>
#include <ctime>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    time_t timer = time(NULL);
    struct tm* t = localtime(&timer);

    int y = t->tm_year + 1900;
    int m = t->tm_mon + 1;
    int d = t->tm_mday;
    int h = t->tm_hour;

    h += 9;
    if (h >= 24) {
        d++;
    }

    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            if (d == 32) {
                d = 1;
                m++;
            }
            break;
        
        case 4:
        case 6:
        case 9:
        case 11:
            if (d == 31) {
                d = 1;
                m++;
            }

        case 2:
            if ((y % 4 == 0 && y % 100 != 0) || y % 100 == 0 && y % 400 == 0) {
                if (d == 30) {
                    d = 1;
                    m++;
                }
            } else {
                if (d == 29) {
                    d = 1;
                    m++;
                }
            }

        default:
            break;
    }

    if (m == 13) {
        m = 1;
        y++;
    }

    cout.width(4);
    cout.fill('0');
    cout << y;

    cout << "-";

    cout.width(2);
    cout.fill('0');
    cout << m;
    cout << "-";

    cout.width(2);
    cout.fill('0');
    cout << d;
    cout << "\n";

    return 0;
}