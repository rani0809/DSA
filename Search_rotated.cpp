/*  An element in a sorted array can be found in O(log n) time via binary search.
    So for instance, 1 2 3 4 5 might become 3 4 5 1 2 after rotation.
    Devise a way to find an element in the rotated array in O(log n) time.

    SOLUTION:
    The interesting property of a sorted + rotated array is that when you divide
    it into two halves, atleast one of the two halves will always be sorted.

    Let input array, arr[] = [4,5,6,7,8,9,1,2,3]
    number of elements, n = 9 and mid index = (0+8)/2 = 4.

    Left part = {4, 5, 6, 7, 8} and Right part = {9, 1, 2, 3}
    Here left part is sorted and right part isn't. If mid happens to be the
    point of rotation them both left and right sub-arrays will be sorted.

    We can easily know which half is sorted by comparing start and end element of each half.

    Once we find which half is sorted we can see if the key is present in that half -
    simple comparison with the extremes.

    If the key is present in that half we recursively call the function on that half
    else we recursively call our search on the other half.

    We are discarding one half of the array in each call which makes this algorithm O(logN)
*/

#include <iostream>
using namespace std;

int searchRotated (int arr[],int low, int high, int key) {
    int mid = low + (high-low)/2;

    // Key is not present
    if (low > high)
        return -1;

    // Key found
    if (arr[mid] == key)
        return mid;

    // If left half is sorted
    if (arr[low] <= arr[mid]) {
        // If key is present in left half
        if (arr[low] <= key && arr[mid] >= key)
            return searchRotated(arr, low, mid-1, key);
        // Else search right half
        else
            return searchRotated(arr, mid+1, high, key);
    }
    // If right half is sorted
    else {
        // If key is present in right half
        if (arr[mid] <= key && arr[high]>=key)
            return searchRotated(arr, mid+1, high, key);
        // Else search left half
        else
            return searchRotated(arr, low, mid-1, key);
    }
}

/* ---------------------- MAIN DRIVER CODE ------------------- */
int main() {
    int size, key, position;

    cout << "Size = ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << "Key = ";
    cin >> key;

    position = searchRotated (arr, 0, size-1, key);
    cout << position << endl;

    return 0;
}
