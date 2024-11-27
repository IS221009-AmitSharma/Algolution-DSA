// Palindrome Phrase Check

#include <iostream>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    string cleaned = "";
    
    for (char c : s) {
        if (isalnum(c)) {
            cleaned += tolower(c);
        }
    }

    int left = 0, right = cleaned.size() - 1;
    while (left < right) {
        if (cleaned[left] != cleaned[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string s1 = "A man, a plan, a canal: Panama";
    string s2 = "race a car";
    
    cout << isPalindrome(s1) << endl;  
    cout << isPalindrome(s2) << endl;  

    return 0;
}
