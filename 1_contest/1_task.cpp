#include <iostream>
#include <vector>


using namespace std;

bool binSearch(vector<int> &arr, int x) {
    int l = 0, r = arr.size() - 1;
    
    while (l <= r) {
        int m = l + (r - l) / 2;
        
        if (arr[m] == x) {
            return true;
        } 
        
        if (arr[m] < x) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return false;
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
        if (binSearch(arr, x)) {
            cout << "YES ";
        } else {
            cout << "NO ";
        }
    }

    cout << '\n';
    return 0;
}