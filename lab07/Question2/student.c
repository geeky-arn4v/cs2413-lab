/*
Question 2: Merge Sort

Description:
Implement merge sort to sort an integer array in ascending order.

Merge sort is a divide-and-conquer algorithm:
1. Divide the array into two halves.
2. Recursively sort each half.
3. Merge the two sorted halves into one sorted array.

You should implement:

    void mergeSort(int arr[], int size);

You may design your own helper functions.
Suggested helper functions:

    void mergeSortHelper(int arr[], int left, int right);
    void merge(int arr[], int left, int mid, int right);

Example:
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]

Notes:
- If the array is empty or has only one element, do nothing.
- You may use temporary arrays inside your merge function.
*/

static void merge(int arr[], int left, int mid, int right, int temp[]) {
    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
}

static void mergeSortHelper(int arr[], int left, int right, int temp[]) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSortHelper(arr, left, mid, temp);
    mergeSortHelper(arr, mid + 1, right, temp);
    merge(arr, left, mid, right, temp);
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }
    int temp[size];
    mergeSortHelper(arr, 0, size - 1, temp);
}
