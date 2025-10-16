#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    set<int> st;
    long long ans = 0;
    int l = 0;

    for (int r = 0; r < n; r++) {
        // যতক্ষণ পর্যন্ত duplicate আছে, left move করো
        while (st.find(v[r]) != st.end()) {
            st.erase(v[l]);
            l++;
        }

        st.insert(v[r]);
        ans += (r - l + 1);
    }

    cout << ans << "\n";
    return 0;
}
