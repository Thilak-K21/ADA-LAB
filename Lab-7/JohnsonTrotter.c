#include <stdio.h>

#define MAX 100
#define LEFT -1
#define RIGHT 1

typedef struct {
    int value;
    int dir; // -1 for LEFT, 1 for RIGHT
} Element;

void printPermutation(Element perm[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", perm[i].value);
    }
    printf("\n");
}

int getMobile(Element perm[], int n) {
    int mobile = 0;
    for (int i = 0; i < n; i++) {
        int pos = i + perm[i].dir;
        if (pos >= 0 && pos < n && perm[i].value > perm[pos].value) {
            if (perm[i].value > mobile) {
                mobile = perm[i].value;
            }
        }
    }
    return mobile;
}

int findIndex(Element perm[], int n, int mobile) {
    for (int i = 0; i < n; i++) {
        if (perm[i].value == mobile)
            return i;
    }
    return -1;
}

void johnsonTrotter(int n) {
    Element perm[MAX];

    // Step 1: Initialize the first permutation
    for (int i = 0; i < n; i++) {
        perm[i].value = i + 1;
        perm[i].dir = LEFT;
    }

    printPermutation(perm, n); // Print the first permutation

    while (1) {
        int mobile = getMobile(perm, n);
        if (mobile == 0) break; // No mobile integer, we're done

        int pos = findIndex(perm, n, mobile);
        int swapWith = pos + perm[pos].dir;

        // Step 2: Swap mobile element with the adjacent one it points to
        Element temp = perm[pos];
        perm[pos] = perm[swapWith];
        perm[swapWith] = temp;

        pos = swapWith;

        // Step 3: Reverse the direction of all elements greater than mobile
        for (int i = 0; i < n; i++) {
            if (perm[i].value > mobile) {
                perm[i].dir = -perm[i].dir;
            }
        }

        printPermutation(perm, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    printf("Permutations using Johnson-Trotter Algorithm:\n");
    johnsonTrotter(n);

    return 0;
}
