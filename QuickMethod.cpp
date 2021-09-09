/*	Find the quick methods for the following:
    a) Just tell the element at a particular index
       after N left rotations.
    b) Just print the array after N left rotations.
       (Do the same for right rotations as an exercise)

    For a) part, We observe:

    Consider array = {1, 2, 3, 4, 5, 6, 7, 8}
    When k (effective number of rotations) = 3,
    array becomes {4, 5, 6, 7, 8, 1, 2, 3}

    Element       became	      this Element after rotations
    0th (1)		-->  		5th	= (8 - 3 + 0) % 8
    1st (2)		--> 		6th	= (8 - 3 + 1) % 8
    3rd (4)		-->		0th	= (8 - 3 + 3) % 8
    5th (6)		--> 		2nd 	= (8 - 3 + 5) % 8

    ith		-->       	(n - k + i) % n

    For b) part, We will use logic of part a) in a loop.
*/

#include <iostream>
using namespace std;

// Main Logic of Code
void findElement (int arr[], int n, int N, int i) {
    int k = N%n;	// Effective number of rotations
    cout << arr[(n-k+i)%n] << " ";
}

void printRotatedArray (int arr[], int n, int N){
    for (int i = 0; i < n; i++)
        findElement(arr, n, N, i);
    cout << endl;
}

/* ---------------- MAIN DRIVER CODE ------------- */
int main() {
    int size, rotations;

    cout << "Size = ";
    cin >> size;

    int* arr = new int[size];
    for (int i = 0; i < size; i++) {
        cout << "arr[" << i << "] = ";
        cin >> arr[i];
    }

    cout << "Number of Rotations = ";
    cin >> rotations;

    printRotatedArray (arr, size, rotations);

    return 0;
}
