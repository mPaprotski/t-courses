#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll best_diff;
char res_type;
ll res_x;

void update(ll d, char t, ll x) {
    if (best_diff == -1 || d < best_diff) {
        best_diff = d; res_type = t; res_x = x;
    } else if (d == best_diff) {
        if (t == 'V' && res_type == 'H') {
            res_type = 'V'; res_x = x;
        } else if (t == res_type && x < res_x) {
            res_x = x;
        }
    }
}

ll get_sum_h(ll n, ll m, ll x) {
    ll k = (x - 1) * m;
    return k * (k + 1) / 2;
}

ll get_sum_v(ll n, ll m, ll x) {
    return n * (x - 1) * (m * (n - 1) + x) / 2;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    ll nm = n * m;
    ll total_s = nm * (nm + 1) / 2;
    best_diff = -1; // Сброс для нового запроса

    // 1. Ищем лучший вертикальный разрез (V)
    if (m > 1) {
        ll low = 2, high = m, best_v_x = 2;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (2 * get_sum_v(n, m, mid) <= total_s) {
                best_v_x = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        for (ll x = best_v_x; x <= min(m, best_v_x + 1); ++x) {
            if (x >= 2) {
                ll s = get_sum_v(n, m, x);
                ll d = (total_s > 2 * s) ? (total_s - 2 * s) : (2 * s - total_s);
                update(d, 'V', x);
            }
        }
    }

    if (n > 1) {
        ll low = 2, high = n, best_h_x = 2;
        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (2 * get_sum_h(n, m, mid) <= total_s) {
                best_h_x = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        for (ll x = best_h_x; x <= min(n, best_h_x + 1); ++x) {
            if (x >= 2) {
                ll s = get_sum_h(n, m, x);
                ll d = (total_s > 2 * s) ? (total_s - 2 * s) : (2 * s - total_s);
                update(d, 'H', x);
            }
        }
    }

    cout << res_type << " " << res_x << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}