// c program for reversal algorithm of array rotation
#include<stdio.h>

// utility function to print an array
void printArray(int arr[], int size);

// utility function to reverse arr[] from start to end
void revArray(int arr[], int start, int end);

// function to left rotate arr[] of size n by d
void leftRotate(int arr[], int d, int n) {
    if (d == 0)
        return;
    revArray(arr, 0, d-1);
    revArray(arr, d, n-1);
    revArray(arr, 0, n-1);
}

// utility function to print an array
void printArray(int arr[], int size) {
    int i;
    for (i=0; i<size; i++)
        printf("%d ", arr[i]);
}

// function to reverse arr[] from index start to end
void revArray(int arr[], int startArr, int endArr) {
    int temp;
    while (startArr < endArr) {
        temp = arr[startArr];
        arr[startArr] = arr[endArr];
        arr[endArr] = temp;
        startArr++;
        endArr--;
    }
}

// driver program to test above function
int main() {
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 2;

    // in case the rotating factor is greater than array length
    d = d % n;
    leftRotate(arr, d, n);
    printArray(arr, n);
    return 0;
}