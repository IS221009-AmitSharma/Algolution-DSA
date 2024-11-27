// 7. Pairs Adding Up to Digit D:

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int countVowels(string word) {
    int count = 0;
    for (char c : word) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') count++;
    }
    return count;
}

string numberToWords(int num) {
    string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    if (num < 10) return words[num];
    return "hundred";
}

int calculateD(vector<int>& nums) {
    int D = 0;
    for (int num : nums) {
        string word = numberToWords(num);
        D += countVowels(word);
    }
    return D;
}

int findPairs(vector<int>& nums, int D) {
    unordered_map<int, int> freq;
    int pairs = 0;
    for (int num : nums) {
        if (freq[D - num]) pairs += freq[D - num];
        freq[num]++;
    }
    return pairs;
}

int main() {
    vector<int> nums = {1, 2, 3, 4, 5};
    int D = calculateD(nums);
    cout << "Pairs: " << findPairs(nums, D) << endl;
    return 0;
}
