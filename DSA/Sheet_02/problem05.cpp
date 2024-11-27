// Problem 5: Equilibrium Index

#include <iostream>
using namespace std;

int findEquilibriumIndex(int arr[], int n) {
    int totalSum = 0, leftSum = 0;
    
    
    for (int i = 0; i < n; i++) {
        totalSum += arr[i];
    }

    
    for (int i = 0; i < n; i++) {
        totalSum -= arr[i];  
        
        if (leftSum == totalSum) {
            return i + 1;  
        }
        
        leftSum += arr[i];
    }

    return -1;  
}

int main() {
    int arr1[] = {-7, 1, 5, 2, -4, 3, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << findEquilibriumIndex(arr1, n1) << endl;  // Output: 4

    int arr2[] = {1, 2, 3};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << findEquilibriumIndex(arr2, n2) << endl;  // Output: -1

    int arr3[] = {1, 3, 5, 2, 2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    cout << findEquilibriumIndex(arr3, n3) << endl;  // Output: 2

    return 0;
}
