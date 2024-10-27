#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

bool isIsomorphic(string s, string t) {
    if (s.length() != t.length()) {
        return false;
    }

    unordered_map<char, char> mapST;  // Map characters from s to t
    unordered_map<char, char> mapTS;  // Map characters from t to s

    for (int i = 0; i < s.length(); i++) {
        char charS = s[i];
        char charT = t[i];

        // If a mapping exists in s -> t and it doesn't match charT, return false
        if (mapST.find(charS) != mapST.end() && mapST[charS] != charT) {
            return false;
        }

        // If a mapping exists in t -> s and it doesn't match charS, return false
        if (mapTS.find(charT) != mapTS.end() && mapTS[charT] != charS) {
            return false;
        }

        // Create the mappings s -> t and t -> s
        mapST[charS] = charT;
        mapTS[charT] = charS;
    }

    return true;
}

int main() {
    string s,t;
    cin>>s>>t;
    cout<<(isIsomorphic(s,t))<<endl;

    return 0;
}

