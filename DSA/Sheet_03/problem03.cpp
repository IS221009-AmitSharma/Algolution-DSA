// 3. Maximum of Subarrays of Size K:

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

void maxOfSubarrays(vector<int>& arr, int K) {
    deque<int> dq;
    for (int i = 0; i < arr.size(); i++) {
        if (!dq.empty() && dq.front() == i - K) dq.pop_front(); 
        while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back(); 
        dq.push_back(i);

        if (i >= K - 1) cout << arr[dq.front()] << " "; 
    }
    cout << endl;
}

int main() {
    vector<int> arr = {8, 5, 10, 7, 9, 4, 15, 12, 90, 13};
    int K = 4;
    maxOfSubarrays(arr, K);
    return 0;
}
