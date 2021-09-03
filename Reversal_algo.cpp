/*
Let AB be the two parts of the input array where A = arr{0..d-1} and B = arr{d..n-1}.
Then the algorithm for left rotation is :

    Reverse A to get A'B, where A' is reverse of A.         ---- Step 1
    Reverse B to get A'B', where B' is reverse of B.        ---- Step 2
    Reverse all to get (A'B')' = BA.                        ---- Step 3

Let the array be arr[] = {1, 2, 3, 4, 5, 6, 7}, d = 2 and n = 7.
Then A = {1, 2} and B = {3, 4, 5, 6, 7}

    Reverse A, we get A'B = {2, 1, 3, 4, 5, 6, 7}
    Reverse B, we get A'B' = {2, 1, 7, 6, 5, 4, 3}
    Reverse all, we get (A'B')' = {3, 4, 5, 6, 7, 1, 2}

Similarly the algorithm of right rotation is :

    Reverse all, we get (AB)' = B'A' = {7, 6, 5, 4, 3, 2, 1}   ---- Step 3
        Now B' = {7, 6} and A' = {5, 4, 3, 2, 1}
    Reverse B, we get BA' = {6, 7, 5, 4, 3, 2, 1}              ---- Step 1
    Reverse A, we get BA = {6, 7, 1, 2, 3, 4, 5}               ---- Step 2

So just the order of steps is different in left and right rotations,
but the steps remain the same -
    a) Reversing first d elements,
    b) Reversing from d to n elements
    c) Reversing the whole array.

    The time complexity is O(n) and space complexity is O(1).
*/

#include <iostream>
using namespace std;

// Utility Function
void reverseArray (int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++; end--;
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Main Logic of Code
void leftRotate(int arr[], int n, int d) {
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
    reverseArray(arr, 0, n-1);
}

void rightRotate(int arr[], int n, int d) {
    reverseArray(arr, 0, n-1);
    reverseArray(arr, 0, d-1);
    reverseArray(arr, d, n-1);
}

/* ----------------- MAIN DRIVER CODE ---------------- */
int main() {
    int size, rotate;

    cout << "Size = ";
    cin >> size;

    cout << "Rotate = ";
    cin >> rotate;

    // Allocate the arrays dynamically if you ask the
    // size of the array from the user.
    int* arr1 = new int[size];
    int* arr2 = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    printArray(arr1, size);
    leftRotate(arr1, size, rotate);
    printArray(arr1, size);

    printArray(arr2, size);
    rightRotate(arr2, size, rotate);
    printArray(arr2, size);

    return 0;
}
