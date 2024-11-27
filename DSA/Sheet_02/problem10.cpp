// Problem 10: Maximum Length Subarray with Given Sum (Using HashMap)

#include <iostream>
#include <unordered_map>
using namespace std;

void findMaxLengthSubarray(int nums[], int n, int target) {
    unordered_map<int, int> sumMap;
    int sum = 0;
    int maxLength = 0;
    int start = -1, end = -1;

    
    for (int i = 0; i < n; i++) {
        sum += nums[i];

        
        if (sum == target) {
            maxLength = i + 1;
            start = 0;
            end = i;
        }

        
        if (sumMap.find(sum - target) != sumMap.end()) {
            if (i - sumMap[sum - target] > maxLength) {
                maxLength = i - sumMap[sum - target];
                start = sumMap[sum - target] + 1;
                end = i;
            }
        }

        
        if (sumMap.find(sum) == sumMap.end()) {
            sumMap[sum] = i;
        }
    }

    if (start != -1 && end != -1) {
        cout << "Maximum length subarray with sum " << target << ": {";
        for (int i = start; i <= end; i++) {
            cout << nums[i] << (i == end ? "}" : ", ");
        }
        cout << " Length: " << maxLength << endl;
    } else {
        cout << "No subarray with sum " << target << " found." << endl;
    }
}

int main() {
    int nums[] = {5, 6, -5, 5, 3, 5, 3, -2, 0};
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 8;

    findMaxLengthSubarray(nums, n, target);  

    return 0;
}
