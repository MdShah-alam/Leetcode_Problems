#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s) {
    int left=0;
    int right=s.size()-1;

    while(left<right){
        while(left<right && !isalnum(s[left]))
            left++;
        while(left<right && !isalnum(s[right]))
            right--;
        if(tolower(s[left])!=tolower(s[right]))
            return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    string s3 = " ";

    cout << (isPalindrome(s1) ? "true" : "false") << endl;  // Output: true
    cout << (isPalindrome(s2) ? "true" : "false") << endl;  // Output: false
    cout << (isPalindrome(s3) ? "true" : "false") << endl;  // Output: true

    return 0;
}
