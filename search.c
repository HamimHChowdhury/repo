#include <stdio.h>

int search(int numbers[], int low, int high, int value) {
    if (low > high) {
        return -1; // Not found
    }

    int mid = low + (high - low) / 2;

    if (numbers[mid] == value) {
        return mid; // Found
    } else if (numbers[mid] < value) {
        return search(numbers, mid + 1, high, value); // Search right half
    } else {
        return search(numbers, low, mid - 1, value); // Search left half
    }
}

int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    int n, low, high, value;
    fscanf(file, "%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &numbers[i]);
    }
    fscanf(file, "%d %d %d", &low, &high, &value);
    fclose(file);

    int result = search(numbers, low, high, value);
    printf("Result: %d\n", result);

    return 0;
}
