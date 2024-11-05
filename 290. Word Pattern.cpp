#include<bits/stdc++.h>
using namespace std;

bool wordPattern(const string& pattern, const string& s) {
    istringstream iss(s);
    vector<string> words;
    string word;

    // Split the string s into words and store them in a vector
    while (iss >> word) {
        words.push_back(word);
    }

    // If the number of words doesn't match the length of the pattern, return false
    if (words.size() != pattern.size()) {
        return false;
    }

    // Maps to store the character-to-word and word-to-character mappings
    unordered_map<char,string> charToWord;
    unordered_map<string, char> wordToChar;

    for (int i = 0; i < pattern.size(); ++i) {
        char c = pattern[i];
        const string& w = words[i];

        // Check if the current character is already mapped to a different word
        if (charToWord.count(c)) {
            if (charToWord[c] != w) {
                return false;
            }
        } else {
            charToWord[c] = w;
        }

        // Check if the current word is already mapped to a different character
        if (wordToChar.count(w)) {
            if (wordToChar[w] != c) {
                return false;
            }
        } else {
            wordToChar[w] = c;
        }
    }

    return true;
}

int main()
{
    string s="dog cat cat dog";
    string p="abba";
    cout<<wordPattern(p,s)<<endl;

    return 0;
}
