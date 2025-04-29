#include <stdio.h>

int knapsack(int values[], int weights[], int n, int W) {
    int maxValue = 0;
    for (int i = 0; i < (1 << n); i++) {
        int totalWeight = 0, totalValue = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                totalWeight += weights[j];
                totalValue += values[j];
            }
        }
        if (totalWeight <= W && totalValue > maxValue) {
            maxValue = totalValue;
        }
    }

    return maxValue;
}
