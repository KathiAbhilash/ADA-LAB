#include <stdio.h>

int n = 5;
int p[10] = {3, 3, 2, 5, 1};
int w[10] = {10, 15, 10, 12, 8};
int W = 10;

float getTotalValue(float fractions[]) {
    float totalValue = 0;
    for (int i = 0; i < n; i++) {
        totalValue += p[i] * fractions[i];
    }
    return totalValue;
}


float getTotalWeight(float fractions[]) {
    float totalWeight = 0;
    for (int i = 0; i < n; i++) {
        totalWeight += w[i] * fractions[i];
    }
    return totalWeight;
}

int main() {
    float max_value = 0;
    float best_combination[10];
    float current_combination[10];

    for (int i = 0; i <= 10; i++) {
        for (int j = 0; j <= 10; j++) {
            for (int k = 0; k <= 10; k++) {
                for (int l = 0; l <= 10; l++) {
                    for (int m = 0; m <= 10; m++) {
                        current_combination[0] = i / 10.0;
                        current_combination[1] = j / 10.0;
                        current_combination[2] = k / 10.0;
                        current_combination[3] = l / 10.0;
                        current_combination[4] = m / 10.0;

                             float totalWeight = getTotalWeight(current_combination);

                           if (totalWeight <= W) {
                            float totalValue = getTotalValue(current_combination);

                             if (totalValue > max_value) {
                                max_value = totalValue;
                                for (int i = 0; i < n; i++) {
                                    best_combination[i] = current_combination[i];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Maximum value: %.2f\n", max_value);
    printf("Selected items with fractions:\n");
    for (int i = 0; i < n; i++) {
        if (best_combination[i] > 0) {
            printf("Item %d (Profit: %d, Weight: %d, Fraction: %.2f)\n",
                i + 1, p[i], w[i], best_combination[i]);
        }
    }

    return 0;
}
