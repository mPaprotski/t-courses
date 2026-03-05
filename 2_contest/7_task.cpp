#include <iostream>
#include <deque>

using namespace std;

deque<int> left_part, right_part;

void balance() {
    if (left_part.size() < right_part.size()) {
        left_part.push_back(right_part.front());
        right_part.pop_front();
    }
    if (left_part.size() > right_part.size() + 1) {
        right_part.push_front(left_part.back());
        left_part.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        char type;
        cin >> type;
        if (type == '+') {
            int id;
            cin >> id;
            right_part.push_back(id);
            balance();
        } else if (type == '*') {
            int id;
            cin >> id;
            left_part.push_back(id);
            balance();
        } else if (type == '-') {
            cout << left_part.front() << "\n";
            left_part.pop_front();
            balance();
        }
    }
    return 0;
}