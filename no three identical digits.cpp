#include <bits/stdc++.h>
using namespace std;

long long countNumbers(int n) {
    if (n == 1) return 2;
    long long a = 2; // sequences ending with run length 1
    long long b = 0; // sequences ending with run length 2

    for (int i = 2; i <= n; i++) {
        long long new_a = a + b; // switch digits
        long long new_b = a;     // extend same digit (only once)

        a = new_a;
        b = new_b;
    }
    return a + b;
}

int main() {
    int n;
    cin >> n;
    cout << countNumbers(n) << endl;
    return 0;
}

