#include <stdio.h>
//int count = 0;
void swap(int *xp, int *yp,int *c) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
    *c++;
}

void selectionSort(int arr[], int n,int count) {
    int i, j, min_idx;
  
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i], &count);
    }
}

// Function to print an array
void printArray(int arr[], int size,int count) {
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
    printf("%d",count);
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count=0;
    selectionSort(arr, n,count);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
