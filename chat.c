#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

// Function to merge two subarrays in Merge Sort
void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}

int main() {
    int n = 10000; // Adjust the size of the array as needed
    int arr1[n], arr2[n];

    // Initialize arrays with random values
    for (int i = 0; i < n; i++) {
        arr1[i] = rand() % 100000;
        arr2[i] = arr1[i];
    }

    clock_t start, end;
    double cpu_time_used;

    // Measure time for Selection Sort
    start = clock();
    selectionSort(arr1, n);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Selection Sort: %f seconds\n", cpu_time_used);

    for(int i=9000;i<9100;i++) {
      printf("%d ", arr1[i]);
    }
    printf("\n");

    // Reset the array for Merge Sort
    for (int i = 0; i < n; i++) {
        arr1[i] = arr2[i];
    }

    // Measure time for Merge Sort
    start = clock();
    mergeSort(arr1, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Time taken by Merge Sort: %f seconds\n", cpu_time_used);

    return 0;
}
