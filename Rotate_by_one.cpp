/* There is no benefit in writing the big reversal algorithm if we
have to rotate the array by one.

So here is the simple Rotate by one function which takes O(n) time. */

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Main Logic of Code
void leftRotateByOne (int arr[], int n) {
    int temp = arr[0], i;
    for (i = 0; i < n - 1; i++)
        arr[i] = arr[i + 1];
    arr[i] = temp;
}

void rightRotateByOne (int arr[], int n) {
    int temp = arr[n - 1], i;
    for (i = n - 1; i > 0; i--)
        arr[i] = arr[i - 1];
    arr[0] = temp;
}

/* --------------- MAIN DRIVER CODE ------------- */
int main() {
    int size;

    cout << "Size = ";
    cin >> size;

    int* arr1 = new int[size];
    int* arr2 = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr1[i];
        arr2[i] = arr1[i];
    }

    leftRotateByOne (arr1, size);
    printArray (arr1, size);

    rightRotateByOne (arr2, size);
    printArray (arr2, size);

    return 0;
}
