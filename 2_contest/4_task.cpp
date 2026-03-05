#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Group {
    int color;
    int count;
};

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> balls(n);
    for (int i = 0; i < n; ++i) {
        cin >> balls[i];
    }

    stack<Group> s;
    int destroyed = 0;

    for (int i = 0; i < n; ++i) {
        if (!s.empty() && s.top().color == balls[i]) {
            s.top().count++;
        } else {
            if (!s.empty() && s.top().count >= 3) {
                destroyed += s.top().count;
                s.pop();
                
                if (!s.empty() && s.top().color == balls[i]) {
                    s.top().count++;
                } else {
                    s.push({balls[i], 1});
                }
            } else {
                s.push({balls[i], 1});
            }
        }
    }

    if (!s.empty() && s.top().count >= 3) {
        destroyed += s.top().count;
        s.pop();
    }

    cout << destroyed << endl;

    return 0;
}