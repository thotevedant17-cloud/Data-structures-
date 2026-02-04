#include <stdio.h>
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for(j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}
void mergeSort(int arr[], int left, int right) {
if(left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
}

}
void printArray(int arr[], int size) {
for(int i = 0; i < size; i++) {
	printf("%d",arr[i]);
	if (i < size - 1) {
		printf(" ");
	}
}
	printf(" \n");



}

int main() {
    int n;
    
    // Input the size of the array
    printf("");
    scanf("%d", &n);
    
    int arr[n];
    
    // Input the elements of the array
    printf("");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("");
    printArray(arr, n);

    // Sort the array using merge sort
    mergeSort(arr, 0, n - 1);
    
    // Print the sorted array
    printf("");
    printArray(arr, n);

    return 0;
}
