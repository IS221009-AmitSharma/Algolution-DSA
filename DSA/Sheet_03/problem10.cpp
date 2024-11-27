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
