#include <iostream>
using namespace std;

void heap(int myArray[], int n, int i) {
    while (true) {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if (left < n && myArray[left] > myArray[largest])
            largest = left;

        if (right < n && myArray[right] > myArray[largest])
            largest = right;

        if (largest != i) {
            swap(myArray[i], myArray[largest]);
            i = largest;
        } else {
            break;
        }
    }
}

void insert(int myArray[], int &n, int value) {
    if (n == 100) {
        cout << "Heap is full. Cannot insert!" << endl;
        return;
    }

    n++;
    myArray[n - 1] = value;

    int i = n - 1;
    while (i != 0 && myArray[(i - 1) / 2] < myArray[i]) {
        swap(myArray[i], myArray[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}


void print(int heap[], int n) {
    for (int i = 0; i < n; i++)
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    int myArray[100]
    int n = 0;

    
    insert(myArray, n, 20);
    insert(myArray, n, 15);
    insert(myArray, n, 30);
    insert(myArray, n, 40);
    insert(myArray, n, 10);

    cout << "Max-Heap array after insertions: ";
    print(myArray, n);

    return 0;
}
