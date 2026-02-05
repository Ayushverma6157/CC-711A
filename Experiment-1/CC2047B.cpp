#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> cnt(26, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }

    int mx = 0;
    int mn = n + 1;
    char high = s[0];
    char low = s[0];

    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            if (cnt[i] >= mx) {
                mx = cnt[i];
                high = i + 'a';
            }
        }
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] > 0) {
            if (cnt[i] <= mn) {
                if (i + 'a' != high) {
                    mn = cnt[i];
                    low = i + 'a';
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == low) {
            s[i] = high;
            break;
        }
    }

    cout << s << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}