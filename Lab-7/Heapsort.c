#include <stdio.h>

#define MAX 100

void topDownHeapify(int a[], int n) {
    for (int k = 1; k < n; k++) {
        int item = a[k];
        int c = k;
        int p = (c - 1) / 2;
        while (c > 0 && item > a[p]) {
            a[c] = a[p];
            c = p;
            p = (c - 1) / 2;
        }
        a[c] = item;
    }
}

void bottomUpHeapify(int a[], int n) {
    for (int p = (n - 1) / 2; p >= 0; p--) {
        int item = a[p];
        int c = 2 * p + 1;

        while (c < n) {
            if (c + 1 < n && a[c] < a[c + 1]) {
                c = c + 1;
            }

            if (item < a[c]) {
                a[p] = a[c];
                p = c;
                c = 2 * p + 1;
            } else {
                break;
            }
        }
        a[p] = item;
    }
}

void heapSort(int a[], int n) {
    // Step 1: Build the heap using top-down
    topDownHeapify(a, n);

    // Step 2: Repeatedly remove max and fix heap using bottom-up
    for (int i = n - 1; i > 0; i--) {
        // Swap max (a[0]) with last element
        int temp = a[0];
        a[0] = a[i];
        a[i] = temp;

        // Recreate heap on reduced array
        bottomUpHeapify(a, i);
    }
}

int main() {
    int a[MAX], n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    heapSort(a, n);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
