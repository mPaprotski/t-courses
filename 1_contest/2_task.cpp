#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int lower_bound(vector<int> &arr, int num) {
    int l = 0, r = arr.size();

    while (l < r) {
        int m = l + (r - l) / 2;
        if (arr[m] >= num) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < m; i++) {
    int x;
    cin >> x;
    
    int ind = lower_bound(arr, x);

    if (ind == n) {
        cout << arr[n - 1] << '\n';
    }
    
    else if (ind == 0) {
        cout << arr[0] << '\n';
    }
    else {
        int right_val = arr[ind];
        int left_val = arr[ind - 1];

        if (abs(x - left_val) <= abs(right_val - x)) {
            cout << left_val << '\n';
        } else {
            cout << right_val << '\n';
        }
    }
}

    return 0;
}