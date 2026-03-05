#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<ll> a(n);
    vector<ll> pref(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        pref[i + 1] = pref[i] + a[i]; 
    }

    vector<int> left(n), right(n);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        left[i] = s.empty() ? 0 : s.top() + 1;
        s.push(i);
    }

    while (!s.empty()) s.pop();

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && a[s.top()] >= a[i]) {
            s.pop();
        }
        right[i] = s.empty() ? n - 1 : s.top() - 1;
        s.push(i);
    }

    ll max_val = -1;
    for (int i = 0; i < n; ++i) {
        // Сумма на отрезке [left[i], right[i]]
        ll current_sum = pref[right[i] + 1] - pref[left[i]];
        ll result = a[i] * current_sum;
        if (result > max_val) {
            max_val = result;
        }
    }

    cout << max_val << endl;

    return 0;
}