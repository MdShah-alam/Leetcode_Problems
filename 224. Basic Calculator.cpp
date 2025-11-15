#include <bits/stdc++.h>
using namespace std;

int calculate(string s) {
    stack<int> st;
    int result = 0;
    int sign = 1;
    int num = 0;

    for (int i = 0; i < s.size(); i++) {
        char ch = s[i];

        if (isdigit(ch)) {
            num = num * 10 + (ch - '0');
        } else if (ch == '+') {
            result += sign * num;
            num = 0;
            sign = 1;
        } else if (ch == '-') {
            result += sign * num;
            num = 0;
            sign = -1;
        } else if (ch == '(') {
            // Push current result and sign to stack
            st.push(result);
            st.push(sign);
            result = 0;
            sign = 1;
        } else if (ch == ')') {
            result += sign * num;
            num = 0;
            result *= st.top(); st.pop(); // Multiply by sign
            result += st.top(); st.pop(); // Add to previous result
        }
    }
    result += sign * num;
    return result;
}

int main() {
    string s;
    getline(cin, s);
    cout << calculate(s) << endl;
    return 0;
}
