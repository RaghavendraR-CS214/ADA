#include <stdio.h>
#include <stdlib.h>

void bottomUp_heapify(int a[], int n) {
    for(int p = (n - 1)/2; p>=0; p--) {
        int item = a[p];
        int c = 2*p + 1;
        while(c <= n-1) {
            if(c + 1 <= n - 1) {
                if(a[c] < a[c + 1]) {
                    c = c + 1;
                }
            }
            if(item < a[c]) {
                a[p] = a[c];
                p = c;
                c = 2*p + 1;
            } else {
                break;
            }
        }
        a[p] = item;
    }
}

void heapSort(int a[], int n) {
    bottomUp_heapify(a, n);
    for(int i=n-1; i>=0; i--) {
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        bottomUp_heapify(a, n);
    }

    for(int i=0; i<n; i++) {
        printf("%d ", a[i]);
    }
}

void main() {
     int arr[100] = { 20, 18, 5, 15, 3, 2 };
    int n = 6;

    // Displaying original array
    printf("Original Array : ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    heapSort(arr, n);

    return 0;
}
