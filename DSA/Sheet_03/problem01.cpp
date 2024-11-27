// 1. Square-Free Numbers:

#include <iostream>
#include <cmath>
using namespace std;

bool isSquareFree(int n) {
    for (int i = 2; i * i <= n; i++) {
        if (n % (i * i) == 0) return false; 
    }
    return true;
}

int countSquareFreeNumbers(int N) {
    int count = 0;
    for (int i = 2; i <= N; i++) {
        if (N % i == 0 && isSquareFree(i)) count++;
    }
    return count;
}

int main() {
    int N;
    cin >> N;
    cout << countSquareFreeNumbers(N) << endl;
    return 0;
}
