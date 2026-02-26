#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int count[26] = {0};
    for (char c : s) {
        count[c - 'A']++;
    }

    string left;
    left.reserve(n);

    for (int i = 0; i < 26; ++i) {
        left.append(count[i]/2, char('A' + i));
    }

    char center = 0;
    for (int i = 0; i < 26; ++i) {
        if (count[i] % 2 == 1) {
            center = char('A' + i);
            break;
        }
    }

    string right = left;
    reverse(right.begin(), right.end());

    if (center) {
        cout << left << center << right << '\n';
    } else {
        cout << left << right << '\n';
    }

    return 0;
}