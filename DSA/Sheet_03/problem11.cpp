// 11. Anagramic Palindrome:

#include <iostream>
#include <unordered_map>
using namespace std;

bool canFormPalindrome(string str) {
    unordered_map<char, int> freq;
    for (char c : str) freq[c]++;
    int oddCount = 0;
    for (auto& pair : freq) {
        if (pair.second % 2 != 0) oddCount++;
    }
    return oddCount <= 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << (canFormPalindrome(str) ? "Yes" : "No") << endl;
    }
    return 0;
}
