#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Element {
    int value;
    int min_val;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<Element> stack;
    stack.reserve(n); 

    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;
        if (type == 1) {
            int x;
            cin >> x;
            if (stack.empty()) {
                stack.push_back({x, x});
            } else {
                stack.push_back({x, min(x, stack.back().min_val)});
            }
        } else if (type == 2) {
            stack.pop_back();
        } else if (type == 3) {
            cout << stack.back().min_val << "\n";
        }
    }

    return 0;
}