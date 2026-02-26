#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

long double f(long double x, long double a, long double b, long double c, long double d) {
    return (((a*x + b)*x + c)*x + d);
}


int main() {
    long double a, b, c, d, x;
    cin >> a >> b >> c >> d;

    long double l = -1.0L, r = 1.0L;
    long double fl = f(l, a, b, c, d);
    long double fr = f(r, a, b, c, d);

    for (int i = 0; i < 200 && fl * fr > 0; i++) {
        l *= 2.0L;
        r *= 2.0L;
        fl = f(l, a, b, c, d);
        fr = f(r, a, b, c, d);
    }

    for (int i = 0; i < 200; i++) {
        long double m = (l + r) / 2.0L;
        long double fm = f(m, a, b, c, d);

        if (fl * fm <= 0) {
            r = m;
            fr = fm;
        } else {
            l = m;
            fl = fm;
        }
    }

    cout << setprecision(15) << (l + r) / 2.0L << '\n';
    return 0;
}