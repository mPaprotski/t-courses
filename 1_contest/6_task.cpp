#include <vector>
#include <iostream>

using namespace std;

long long merge(vector<long long> &arr, vector<long long> &temp, int l, int m, int r) {
    int i = l, j = m+1, k = l;
    long long inv = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv += (m - i + 1);
        }
    }

    while (i <= m) {
        temp[k++] = arr[i++];
    }
    while (j <= r) {
        temp[k++] = arr[j++];
    }
        
    for (int idx = l; idx <= r; idx++) {
        arr[idx] = temp[idx];
    }

    return inv;    
}

long long mergeSort(vector<long long> &arr, vector<long long> &temp, int l, int r) {
    long long inv = 0;
    if (l < r) {
        int m = l + (r - l) / 2;

        inv += mergeSort(arr, temp, l, m);
        inv += mergeSort(arr, temp, m+1, r);
        inv += merge(arr, temp, l, m, r);
    }
    return inv;
}

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n), temp(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long inv = mergeSort(arr, temp, 0, n-1);

    cout << inv << '\n';
    for (size_t i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }

    cout << '\n';
    return 0;
}
