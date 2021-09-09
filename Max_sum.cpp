/*	Find maximum value of Sum(i*arr[i]) when only right
    rotations are allowed.

    A simple solution of adding and checking sum at each
    element takes O(n^2) complexity.

    An efficient solution with O(n) complexity has the idea
    to calculate next rotation value from previous rotation,
    i.e., calculate Rj from Rj-1, where -
        Rj = Sum(i*arr[i]) after j rotations

    R0 = 0*a[0] + 1*a[1] + 2*a[2] + 3*a[3] + .... + (n-2)*a[n-2] + (n-1)*a[n-1]
    R1 = 0*a[1] + 1*a[2] + 2*a[3] + .... + (n-3)*a[n-2] + (n-2)*a(n-1) + (n-1)*a[0]
    R2 = 0*a[2] + 1*a[3] + .... + (n-4)*a[n-2] + (n-3)*a[n-1] + (n-2)*a[0] + (n-1)*a[1]

    R0 - R1 = 1*a[1] + 1*a[2] + 1*a[3] + ..... + 1*a[n-2] + 1*a[n-1] - (n-1)*a[0]
        = Sum of elements of array - n*a[0]

    R1 - R2 = 1*a[2] + 1*a[3] + ..... + 1*a[n-2] + 1*a[n-1] + 1*a[0] - (n-1)*a[1]
        = Sum of elements of array - n*a[1]

    Hence,	Rj = Rj-1 + n*a[j-1] - Sum of elements of array;

    1) Complete the sum of elements of array, in arrSum
    2) Compute R0 from the given arrray
    3) Initialize result: maxVal = currVal // maxVal is result
    4) Do following for j = 1 to n-1
        a) currVal = currVal + arrSum-n*arr[n-j];
        b) If (currVal > maxVal)
            maxVal = currVal
            rotation = j
    5) Print maxVal and rotation
*/

#include <iostream>
using namespace std;

// Main Logic of Code
void maxSum(int arr[], int n) {
    int arrSum = 0;  // Sum of arr[i]
    int currVal = 0;  // Sum of i*arr[i]
    int rotation = 0; // Num of rotations at which sum is max

    for (int i=0; i<n; i++) {
        arrSum = arrSum + arr[i];
        currVal = currVal+(i*arr[i]);
    }

    int maxVal = currVal;
    for (int j=1; j<n; j++) {
        currVal = currVal + n*arr[j-1] - arrSum;
        if (currVal > maxVal) {
            maxVal = currVal;
            rotation = j;
        }
    }

    cout << "Max Sum(i*arr[i]): " << maxVal << " after " << rotation << " rotations.\n";
}

/* --------------- MAIN DRIVER CODE ---------------- */
int main() {
    int size;

    cout << "Size = ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    maxSum (arr, size);

    return 0;
}
