#include <stdio.h>

// Structure to hold item details
typedef struct {
    int weight;
    int profit;
    float ratio;
} Item;

// Function to swap two items
void swap(Item *a, Item *b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

// Function to sort items by decreasing profit/weight ratio
void sortItems(Item items[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(items[j].ratio < items[j + 1].ratio) {
                swap(&items[j], &items[j + 1]);
            }
        }
    }
}

// Fractional Knapsack Function
float fractionalKnapsack(Item items[], int n, int capacity) {
    sortItems(items, n);

    float totalProfit = 0.0;
    int currentWeight = 0;

    for(int i = 0; i < n; i++) {
        if(currentWeight + items[i].weight <= capacity) {
            // Take whole item
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
        } else {
            // Take fractional part
            int remain = capacity - currentWeight;
            totalProfit += (items[i].profit * ((float)remain / items[i].weight));
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    for(int i = 0; i < n; i++) {
        printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    float maxProfit = fractionalKnapsack(items, n, capacity);
    printf("Maximum profit = %.2f\n", maxProfit);

    return 0;
}
