#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    int l = 0, r = n;
    while (l < r) {
        int m = (l + r + 1) / 2;
        cout << m << '\n';
        cout.flush();

        string ans;
        cin >> ans;

        if (ans == ">=") {
            l = m;
        } else {
            r = m - 1;
        }
    }

    cout << "! " << l << '\n';
    return 0;
}
