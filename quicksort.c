#include <stdio.h>
#include <time.h>

int partition(int A[], int low, int high) {
    int pivot = A[low];
    int i = low;
    int j = high;
    do {
        while (A[i] <= pivot && i <= high)
            i++;
        while (A[j] > pivot && j >= low)
            j--;
        if (i < j) {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);
    int temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}

void quicksort(int A[], int low, int high) {
    if (low < high) {
        int partitionline = partition(A, low, high);
        quicksort(A, low, partitionline - 1);
        quicksort(A, partitionline + 1, high);
    }
}

void printarray(int A[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d  ", A[i]);
    printf("\n");
}

int main() {
    int low = 0, A[100], n,ch;
    clock_t start,end;
    printf("Enter the number of elements\n");
    scanf("%d", &n);
    int high = n - 1;
    printf("Enter the elements of array\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Before sorting:\n");
    printarray(A, n);
    start=clock();
    quicksort(A,0,n-1);
    end=clock();
    printf("After sorting:\n");
    printarray(A, n);
    printf("time taken = %f",(end-start)/CLK_TCK);
printf("\n\n do u wish to continue (0/1)\n");
scanf("%d",&ch);
    return 0;
}
