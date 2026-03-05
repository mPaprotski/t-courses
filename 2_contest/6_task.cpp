#include <iostream>
#include <vector>

using namespace std;

int arrival_index[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    vector<int> queue_ids(n * 2); 
    int head = n; 
    int tail = n; 
    int current_time = 0;

    for (int i = 0; i < n; ++i) {
        int type;
        cin >> type;

        if (type == 1) {
            int id;
            cin >> id;
            arrival_index[id] = current_time++; 
            queue_ids[tail++] = id;
        } 
        else if (type == 2) {
            if (head < tail) {
                head++; 
            }
        } 
        else if (type == 3) {
            if (head < tail) {
                tail--;
                current_time--;
            }
        } 
        else if (type == 4) {
            int q;
            cin >> q;
            int first_person_idx = current_time - (tail - head);
            cout << arrival_index[q] - first_person_idx << "\n";
        } 
        else if (type == 5) {
            if (head < tail) {
                cout << queue_ids[head] << "\n";
            }
        }
    }

    return 0;
}