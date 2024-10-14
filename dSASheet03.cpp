// 5)Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            st.push(c);
        } else {
            if (st.empty()) return false;

            char top = st.top();
            if ((c == ')' && top == '(') ||
                (c == '}' && top == '{') ||
                (c == ']' && top == '[')) {
                st.pop();
            } else {
                return false;
            }
        }
    }

    return st.empty();
}

int main() {
    string s = "([]){}";
    if (isValid(s)) {
        cout << "The string is valid." << endl;
    } else {
        cout << "The string is invalid." << endl;
    }

    return 0;
}


// 6)Cyclic Palindrome.


// Approach 1

#include <iostream>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int minCyclicShiftsToPalindrome(string s) {
    int n = s.length();
    
    for (int i = 0; i < n; ++i) {
        
        rotate(s.begin(), s.begin() + 1, s.end());
        
        
        if (isPalindrome(s)) {
            return i + 1;
        }
    }
    
    return -1;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        string s;
        cin >> s;
        
        int result = minCyclicShiftsToPalindrome(s);
        cout << result << endl;
    }
    
    return 0;
}

// 2nd Approach

#include <bits/stdc++.h>
using namespace std;


bool isPalindrome(const string& s) {
    int n = s.length();
    for (int i = 0; i < n / 2; ++i) {
        if (s[i] != s[n - i - 1]) {
            return false;
        }
    }
    return true;
}


int minCyclicShiftsToPalindrome(string s) {
    int n = s.length();
    for (int i = 0; i < n; ++i) {
        
        rotate(s.begin(), s.begin() + 1, s.end());

        
        if (isPalindrome(s)) {
            return i + 1;
        }
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    cin.ignore();

    stringstream output;

    for (int t = 0; t < T; ++t) {
        string s;
        getline(cin, s);
        int result = minCyclicShiftsToPalindrome(s);
        output << result << endl;
    }

    cout << output.str();
    return 0;
}


// 9) Given an m x n matrix, the task is to print all elements of the matrix in spiral form.

#include <iostream>
#include <vector>
using namespace std;

void printSpiral(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;

    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;

    while (top <= bottom && left <= right) {
        for (int i = left; i <= right; ++i) {
            cout << matrix[top][i] << " ";
        }
        top++;

  
        for (int i = top; i <= bottom; ++i) {
            cout << matrix[i][right] << " ";
        }
        right--;
        
        if (top <= bottom) {
            for (int i = right; i >= left; --i) {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                cout << matrix[i][left] << " ";
            }
            left++;
        }
    }
    cout << endl;
}

int main() {
    
    vector<vector<int>> matrix1 = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

  
    vector<vector<int>> matrix2 = {
        {1, 2, 3, 4, 5, 6},
        {7, 8, 9, 10, 11, 12},
        {13, 14, 15, 16, 17, 18}
    };

    cout << "Spiral order of matrix 1: ";
    printSpiral(matrix1);

    cout << "Spiral order of matrix 2: ";
    printSpiral(matrix2);

    return 0;
}


// 10)Given an array of n positive integers. We are required to write a program to print the minimum product of k integers of the given array

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minProductOfKIntegers(vector<int>& arr, int k) {
    
    sort(arr.begin(), arr.end());

    int product = 1;
    for (int i = 0; i < k; ++i) {
        product *= arr[i];
    }
    return product;
}

int main() {
    
    vector<int> arr1 = {198, 76, 544, 123, 154, 675};
    int k1 = 2;
    cout << "Minimum product of " << k1 << " integers: " << minProductOfKIntegers(arr1, k1) << endl;

    
    vector<int> arr2 = {11, 8, 5, 7, 5, 100};
    int k2 = 4;
    cout << "Minimum product of " << k2 << " integers: " << minProductOfKIntegers(arr2, k2) << endl;

    return 0;
}


// 12)Write an algorithm to determine if a number n is happy.


#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int sumOfSquares(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    return sum;
}

bool isHappy(int n) {
    unordered_set<int> seen;
    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = sumOfSquares(n);
    }
    return n == 1;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    if (isHappy(n)) {
        cout << n << " is a happy number." << endl;
    } else {
        cout << n << " is not a happy number." << endl;
    }

    return 0;
}
