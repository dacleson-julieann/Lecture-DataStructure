// program to search a element in a sorted and pivoted array
#include<stdio.h>

int findPivot(int[], int, int);
int binarySearch(int[], int, int, int);

//searches an element key in a pivoted sorted array arrp[] of size n
int pivotedBinarySearch(int arr[], int n, int key) {
    int pivot = findPivot(arr, 0, n - 1);
    // if we didn;t find a pivot, then array is not rotated at all.
    if (pivot == -1)
        return binarySearch(arr, 0, n-1, key);

    // if we found a pivot, then first compare with pivot and then search in two subarrays around pivot.
    if (arr[pivot] == key)
        return pivot;
    if (arr[0] <= key)
        return binarySearch(arr, 0, pivot - 1, key);
    return binarySearch(arr, pivot + 1, n - 1, key);
}

// function to get pivot. for array 3,4,5,6,1,2 it returns 3 (index of 6)
int findPivot(int arr[], int low, int high){
    // base cases
    if(high < low)
        return -1;
    if(high == low)
        return low;

    int mid = (low + high)/2; // low + (high-low)/2

    if (mid < high && arr[mid] > arr[mid + 1])
        return mid;
    if (mid > low && arr[mid] < arr[mid - 1])
        return (mid - 1);
    if (arr[low] >= arr[mid])
        return findPivot(arr, low, mid - 1);
    return findPivot(arr, mid + 1, high);
}

// standard binary search functions
int binarySearch(int arr[], int low, int high, int key) {
    if (high < low)
        return -1;
    int mid = (low + high)/2;
    if (key == arr[mid])
        return mid;
    if (key > arr[mid])
        return binarySearch(arr, (mid + 1), high, key);
    return binarySearch(arr, low, (mid - 1), key);
}

// main program to run the above function
int main() {
    // let us search 3 in below array
    int arr[] = {5,6,7,8,9,10,1,2,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 9;
    printf("Index of the element is: %d ", pivotedBinarySearch(arr, n, key));
    return 0;
}


