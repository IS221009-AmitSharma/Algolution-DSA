// Problem 6: Find a Pair with a Given Sum in a Sorted Array

// Part (a): Naive Approach
#include <iostream>
using namespace std;

void findPairNaive(int arr[], int n, int X) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == X) {
                cout << "Pair found: (" << arr[i] << ", " << arr[j] << ")" << endl;
                return;
            }
        }
    }
    cout << "No pair found." << endl;
}

int main() {
    int arr[] = {1, 2, 4, 5, 7, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 9;

    findPairNaive(arr, n, X);  

    return 0;
}

// Part (b): Two-Pointer Technique

#include <iostream>
using namespace std;

void findPairTwoPointer(int arr[], int n, int X) {
    int left = 0, right = n - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == X) {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")" << endl;
            return;
        }
        else if (sum < X) {
            left++;
        }
        else {
            right--;
        }
    }

    cout << "No pair found." << endl;
}

int main() {
    int arr[] = {1, 2, 4, 5, 7, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int X = 9;

    findPairTwoPointer(arr, n, X);  

    return 0;
}
