#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct Operation {
    int type;
    int count;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> path1(n);
    for (int i = 0; i < n; ++i) {
        cin >> path1[i];
    }

    stack<int> dead_end;
    vector<Operation> ops;
    int next_needed = 1;
    int current_idx = 0;

    while (current_idx < n || !dead_end.empty()) {
        if (!dead_end.empty() && dead_end.top() == next_needed) {
            int count = 0;
            while (!dead_end.empty() && dead_end.top() == next_needed) {
                dead_end.pop();
                next_needed++;
                count++;
            }
            ops.push_back({2, count});
        } 
        else if (current_idx < n) {
            dead_end.push(path1[current_idx]);
            ops.push_back({1, 1});
            current_idx++;
        } 
        else {
            cout << 0 << endl;
            return 0;
        }
    }

    if (ops.empty()) return 0;

    vector<Operation> merged;
    merged.push_back(ops[0]);

    for (size_t i = 1; i < ops.size(); ++i) {
        if (ops[i].type == merged.back().type) {
            merged.back().count += ops[i].count;
        } else {
            merged.push_back(ops[i]);
        }
    }

    cout << merged.size() << "\n";
    for (const auto& op : merged) {
        cout << op.type << " " << op.count << "\n";
    }

    return 0;
}