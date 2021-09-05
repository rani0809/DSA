/*
    Given an array, split it from a specified position and move
    the first part of array add to the end.

    Input : arr[] = {12, 10, 5, 6, 52, 36}
            k = 2
    Output : arr[] = {5, 6, 52, 36, 12, 10}
    Explanation : Split from index 2 and first part {12, 10}
              add to the end .

    Input : arr[] = {3, 1, 2}
           k = 1
    Output : arr[] = {1, 2, 3}
    Explanation : Split from index 1 and first part add to the end.

    METHOD:

    This problem can be solved in O(n) time using the reversal algorithm:
        1. Reverse array from 0 to n–1 (where n is size of the array).
        2. Reverse array from 0 to n–k–1.
        3. Reverse array from n–k to n-1.
*/

#include <iostream>
using namespace std;

// Auxiliary Function
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; end--;
    }
}

// Main Logic of Code
void splitArray(int arr[], int n, int k) {
    reverseArray(arr, 0, n - 1);
    reverseArray(arr, 0, n - k - 1);
    reverseArray(arr, n - k, n - 1);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

/* --------------- MAIN DRIVER CODE ----------- */
int main() {
    int size, index;

    cout << "Size = ";
    cin >> size;

    cout << "Split upto index = ";
    cin >> index;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    splitArray(arr, size, index);
    printArray(arr, size);

    return 0;
}
