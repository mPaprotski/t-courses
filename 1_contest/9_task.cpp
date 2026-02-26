#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> is_one(n + 1, 0);
    
    int rightmost_zero = n;
    
    int misplaced_ones = 0;

    cout << 1;

    for (int k = 1; k <= n; ++k) {
        int p;
        cin >> p;
        
        is_one[p] = 1;
        
        misplaced_ones++;
        
        while (rightmost_zero > 0 && is_one[rightmost_zero]) {
            misplaced_ones--;
            rightmost_zero--;
        }

        cout << " " << 1 + misplaced_ones;
    }

    cout << endl;

    return 0;
}