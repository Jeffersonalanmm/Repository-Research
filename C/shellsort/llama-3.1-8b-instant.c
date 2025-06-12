```c
#include <stdio.h>
#include <stdlib.h>

// Function to perform Shell Sort
void shellSort(int arr[], int n) {
    int gap = n / 2;

    // Loop until the gap is greater than zero
    while (gap > 0) {
        // Loop through the array with the current gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Shift elements to the right until the correct position is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Place the element in its correct position
            arr[j] = temp;
        }

        // Reduce the gap by half for the next iteration
        gap /= 2;
    }
}

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform bubble sort for gap size 1
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Function to merge two sorted subarrays
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = left;

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

    free(L);
    free(R);
}

// Function to perform merge sort
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

// Function to perform quick sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

// Function to perform heap sort
void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to perform counting sort
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int exp = 1;
    while (max / exp > 0) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = 10;
    int** buckets = (int**)malloc(bucketSize * sizeof(int*));
    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int index = (int)((arr[i] / (max / bucketSize)) % bucketSize);
        buckets[index][0] = arr[i];
    }

    for (int i = 0; i < bucketSize; i++) {
        int j = 0;
        for (int k = 1; k < n; k++) {
            if (buckets[i][k - 1] > buckets[i][k]) {
                swap(&buckets[i][k - 1], &buckets[i][k]);
            }
        }
    }

    int k = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < n; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    for (int i = 0; i < bucketSize; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to perform quick select
int partitionQuickSelect(int arr[], int low, int high, int k) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

int quickSelect(int arr[], int n, int k) {
    return quickSelectHelper(arr, 0, n - 1, k);
}

int quickSelectHelper(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = partitionQuickSelect(arr, low, high, k);
    if (k == pivot) {
        return arr[k];
    } else if (k < pivot) {
        return quickSelectHelper(arr, low, pivot - 1, k);
    } else {
        return quickSelectHelper(arr, pivot + 1, high, k);
    }
}

// Function to perform median of three
int medianOfThree(int arr[], int n) {
    int mid = n / 2;
    if (arr[0] > arr[mid]) {
        swap(&arr[0], &arr[mid]);
    }

    if (arr[n - 1] > arr[mid]) {
        swap(&arr[n - 1], &arr[mid]);
    }

    if (arr[0] > arr[1]) {
        swap(&arr[0], &arr[1]);
    }

    return arr[mid];
}

// Function to perform quick select with median of three
int quickSelectMedianOfThree(int arr[], int n, int k) {
    return quickSelectHelperMedianOfThree(arr, 0, n - 1, k);
}

int quickSelectHelperMedianOfThree(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = medianOfThree(arr, high);
    int pivotIndex = partitionQuickSelect(arr, low, high, k);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelectHelperMedianOfThree(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelectHelperMedianOfThree(arr, pivotIndex + 1, high, k);
    }
}

// Function to perform shell sort
void shellSort(int arr[], int n) {
    int gap = n / 2;

    // Loop until the gap is greater than zero
    while (gap > 0) {
        // Loop through the array with the current gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Shift elements to the right until the correct position is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Place the element in its correct position
            arr[j] = temp;
        }

        // Reduce the gap by half for the next iteration
        gap /= 2;
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to perform counting sort
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int exp = 1;
    while (max / exp > 0) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = 10;
    int** buckets = (int**)malloc(bucketSize * sizeof(int*));
    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int index = (int)((arr[i] / (max / bucketSize)) % bucketSize);
        buckets[index][0] = arr[i];
    }

    for (int i = 0; i < bucketSize; i++) {
        int j = 0;
        for (int k = 1; k < n; k++) {
            if (buckets[i][k - 1] > buckets[i][k]) {
                swap(&buckets[i][k - 1], &buckets[i][k]);
            }
        }
    }

    int k = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < n; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    for (int i = 0; i < bucketSize; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to perform quick select
int quickSelect(int arr[], int n, int k) {
    return quickSelectHelper(arr, 0, n - 1, k);
}

int quickSelectHelper(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = partitionQuickSelect(arr, low, high, k);
    if (k == pivot) {
        return arr[k];
    } else if (k < pivot) {
        return quickSelectHelper(arr, low, pivot - 1, k);
    } else {
        return quickSelectHelper(arr, pivot + 1, high, k);
    }
}

// Function to perform median of three
int medianOfThree(int arr[], int n) {
    int mid = n / 2;
    if (arr[0] > arr[mid]) {
        swap(&arr[0], &arr[mid]);
    }

    if (arr[n - 1] > arr[mid]) {
        swap(&arr[n - 1], &arr[mid]);
    }

    if (arr[0] > arr[1]) {
        swap(&arr[0], &arr[1]);
    }

    return arr[mid];
}

// Function to perform quick select with median of three
int quickSelectMedianOfThree(int arr[], int n, int k) {
    return quickSelectHelperMedianOfThree(arr, 0, n - 1, k);
}

int quickSelectHelperMedianOfThree(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = medianOfThree(arr, high);
    int pivotIndex = partitionQuickSelect(arr, low, high, k);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelectHelperMedianOfThree(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelectHelperMedianOfThree(arr, pivotIndex + 1, high, k);
    }
}

// Function to perform shell sort
void shellSort(int arr[], int n) {
    int gap = n / 2;

    // Loop until the gap is greater than zero
    while (gap > 0) {
        // Loop through the array with the current gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Shift elements to the right until the correct position is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Place the element in its correct position
            arr[j] = temp;
        }

        // Reduce the gap by half for the next iteration
        gap /= 2;
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to perform counting sort
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int exp = 1;
    while (max / exp > 0) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = 10;
    int** buckets = (int**)malloc(bucketSize * sizeof(int*));
    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int index = (int)((arr[i] / (max / bucketSize)) % bucketSize);
        buckets[index][0] = arr[i];
    }

    for (int i = 0; i < bucketSize; i++) {
        int j = 0;
        for (int k = 1; k < n; k++) {
            if (buckets[i][k - 1] > buckets[i][k]) {
                swap(&buckets[i][k - 1], &buckets[i][k]);
            }
        }
    }

    int k = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < n; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    for (int i = 0; i < bucketSize; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to perform quick select
int quickSelect(int arr[], int n, int k) {
    return quickSelectHelper(arr, 0, n - 1, k);
}

int quickSelectHelper(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = partitionQuickSelect(arr, low, high, k);
    if (k == pivot) {
        return arr[k];
    } else if (k < pivot) {
        return quickSelectHelper(arr, low, pivot - 1, k);
    } else {
        return quickSelectHelper(arr, pivot + 1, high, k);
    }
}

// Function to perform median of three
int medianOfThree(int arr[], int n) {
    int mid = n / 2;
    if (arr[0] > arr[mid]) {
        swap(&arr[0], &arr[mid]);
    }

    if (arr[n - 1] > arr[mid]) {
        swap(&arr[n - 1], &arr[mid]);
    }

    if (arr[0] > arr[1]) {
        swap(&arr[0], &arr[1]);
    }

    return arr[mid];
}

// Function to perform quick select with median of three
int quickSelectMedianOfThree(int arr[], int n, int k) {
    return quickSelectHelperMedianOfThree(arr, 0, n - 1, k);
}

int quickSelectHelperMedianOfThree(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = medianOfThree(arr, high);
    int pivotIndex = partitionQuickSelect(arr, low, high, k);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelectHelperMedianOfThree(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelectHelperMedianOfThree(arr, pivotIndex + 1, high, k);
    }
}

// Function to perform shell sort
void shellSort(int arr[], int n) {
    int gap = n / 2;

    // Loop until the gap is greater than zero
    while (gap > 0) {
        // Loop through the array with the current gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Shift elements to the right until the correct position is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Place the element in its correct position
            arr[j] = temp;
        }

        // Reduce the gap by half for the next iteration
        gap /= 2;
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to perform counting sort
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int exp = 1;
    while (max / exp > 0) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = 10;
    int** buckets = (int**)malloc(bucketSize * sizeof(int*));
    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int index = (int)((arr[i] / (max / bucketSize)) % bucketSize);
        buckets[index][0] = arr[i];
    }

    for (int i = 0; i < bucketSize; i++) {
        int j = 0;
        for (int k = 1; k < n; k++) {
            if (buckets[i][k - 1] > buckets[i][k]) {
                swap(&buckets[i][k - 1], &buckets[i][k]);
            }
        }
    }

    int k = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < n; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    for (int i = 0; i < bucketSize; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to perform quick select
int quickSelect(int arr[], int n, int k) {
    return quickSelectHelper(arr, 0, n - 1, k);
}

int quickSelectHelper(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = partitionQuickSelect(arr, low, high, k);
    if (k == pivot) {
        return arr[k];
    } else if (k < pivot) {
        return quickSelectHelper(arr, low, pivot - 1, k);
    } else {
        return quickSelectHelper(arr, pivot + 1, high, k);
    }
}

// Function to perform median of three
int medianOfThree(int arr[], int n) {
    int mid = n / 2;
    if (arr[0] > arr[mid]) {
        swap(&arr[0], &arr[mid]);
    }

    if (arr[n - 1] > arr[mid]) {
        swap(&arr[n - 1], &arr[mid]);
    }

    if (arr[0] > arr[1]) {
        swap(&arr[0], &arr[1]);
    }

    return arr[mid];
}

// Function to perform quick select with median of three
int quickSelectMedianOfThree(int arr[], int n, int k) {
    return quickSelectHelperMedianOfThree(arr, 0, n - 1, k);
}

int quickSelectHelperMedianOfThree(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = medianOfThree(arr, high);
    int pivotIndex = partitionQuickSelect(arr, low, high, k);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelectHelperMedianOfThree(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelectHelperMedianOfThree(arr, pivotIndex + 1, high, k);
    }
}

// Function to perform shell sort
void shellSort(int arr[], int n) {
    int gap = n / 2;

    // Loop until the gap is greater than zero
    while (gap > 0) {
        // Loop through the array with the current gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Shift elements to the right until the correct position is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Place the element in its correct position
            arr[j] = temp;
        }

        // Reduce the gap by half for the next iteration
        gap /= 2;
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to perform counting sort
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int exp = 1;
    while (max / exp > 0) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize = 10;
    int** buckets = (int**)malloc(bucketSize * sizeof(int*));
    for (int i = 0; i < bucketSize; i++) {
        buckets[i] = (int*)malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++) {
        int index = (int)((arr[i] / (max / bucketSize)) % bucketSize);
        buckets[index][0] = arr[i];
    }

    for (int i = 0; i < bucketSize; i++) {
        int j = 0;
        for (int k = 1; k < n; k++) {
            if (buckets[i][k - 1] > buckets[i][k]) {
                swap(&buckets[i][k - 1], &buckets[i][k]);
            }
        }
    }

    int k = 0;
    for (int i = 0; i < bucketSize; i++) {
        for (int j = 0; j < n; j++) {
            arr[k++] = buckets[i][j];
        }
    }

    for (int i = 0; i < bucketSize; i++) {
        free(buckets[i]);
    }
    free(buckets);
}

// Function to perform quick select
int quickSelect(int arr[], int n, int k) {
    return quickSelectHelper(arr, 0, n - 1, k);
}

int quickSelectHelper(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = partitionQuickSelect(arr, low, high, k);
    if (k == pivot) {
        return arr[k];
    } else if (k < pivot) {
        return quickSelectHelper(arr, low, pivot - 1, k);
    } else {
        return quickSelectHelper(arr, pivot + 1, high, k);
    }
}

// Function to perform median of three
int medianOfThree(int arr[], int n) {
    int mid = n / 2;
    if (arr[0] > arr[mid]) {
        swap(&arr[0], &arr[mid]);
    }

    if (arr[n - 1] > arr[mid]) {
        swap(&arr[n - 1], &arr[mid]);
    }

    if (arr[0] > arr[1]) {
        swap(&arr[0], &arr[1]);
    }

    return arr[mid];
}

// Function to perform quick select with median of three
int quickSelectMedianOfThree(int arr[], int n, int k) {
    return quickSelectHelperMedianOfThree(arr, 0, n - 1, k);
}

int quickSelectHelperMedianOfThree(int arr[], int low, int high, int k) {
    if (low == high) {
        return arr[low];
    }

    int pivot = medianOfThree(arr, high);
    int pivotIndex = partitionQuickSelect(arr, low, high, k);

    if (k == pivotIndex) {
        return arr[k];
    } else if (k < pivotIndex) {
        return quickSelectHelperMedianOfThree(arr, low, pivotIndex - 1, k);
    } else {
        return quickSelectHelperMedianOfThree(arr, pivotIndex + 1, high, k);
    }
}

// Function to perform shell sort
void shellSort(int arr[], int n) {
    int gap = n / 2;

    // Loop until the gap is greater than zero
    while (gap > 0) {
        // Loop through the array with the current gap
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j = i;

            // Shift elements to the right until the correct position is found
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Place the element in its correct position
            arr[j] = temp;
        }

        // Reduce the gap by half for the next iteration
        gap /= 2;
    }
}

// Function to perform heap sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// Function to perform counting sort
void countingSort(int arr[], int n, int exp) {
    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Function to perform radix sort
void radixSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int exp = 1;
    while (max / exp > 0) {
        countingSort(arr, n, exp);
        exp *= 10;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    int bucketSize