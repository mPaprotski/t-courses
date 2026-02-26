#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

double f(double x) {
    return x * x + sqrt(x + 1);
}

int main() {
    double s;
    cin >> s;

    double l = 0, r = 100000;

    for (int i = 0; i < 100; i++) {
        double m = l + (r - l) / 2;
        if (f(m) < s) {
            l = m;
        } else {
            r = m;
        }
    }

    cout << setprecision(15) << l << '\n';
    return 0;
}