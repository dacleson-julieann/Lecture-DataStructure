// c program to rotate an array b d elements
// array rotation - method juggling algorithm

#include <stdio.h>

// function to print array
void printArray(int arr[], int size);

// function to get greatest common of a and b
int gcd(int a, int b);

// function to left rotate arr[] of size n by d
void leftRotate(int arr[], int d, int n) {
    int i, j, k, temp;
    int g_c_d = gcd(d, n);
    for (i=0; i<g_c_d; i++) {
        // move i-th values of blocks
        temp = arr[i];
        j=i;
        while (1) {
            k=j+d;
            if(k>=n)
                k=k-n;
            if(k==i)
                break;
            arr[j] = arr[k];
            j=k;
        }
        arr[j] = temp;
    }
}

// utility function to print array
void printArray(int arr[], int n) {
    int i;
    for (i=0; i<n; i++)
        printf("%d ",arr[i]);
}

// utility function to get greatest common of a and b
int gcd(int a, int b) {
    if (b==0)
        return a; // I got it here my mistake I just end the program.. :D insert return 0;
    else
        return gcd(b,a%b);
}

// main program to run/test above functions
int main() {
    int arr[] = {1,2,3,4,5,6,7};
    leftRotate(arr,2,7);
    printArray(arr,7);
    return 0;
}