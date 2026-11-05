#include <stdio.h>
#define MAX_SIZE 100

void printArray(int numbers[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d", numbers[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

void bubbleSort(int numbers[], int size) {
    int i, j, temp;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - 1 - i; j++) {
            if (numbers[j] > numbers[j + 1]) {
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

void selectionSort(int numbers[], int size) {
    int i, j, smallest, temp;
    for (i = 0; i < size - 1; i++) {
        smallest = i;
        for (j = i + 1; j < size; j++) {
            if (numbers[j] < numbers[smallest]) {
                smallest = j;
            }
        }
        temp = numbers[i];
        numbers[i] = numbers[smallest];
        numbers[smallest] = temp;
    }
}

void insertionSort(int numbers[], int size) {
    int i, j, value;
    for (i = 1; i < size; i++) {
        value = numbers[i];
        j = i - 1;
        while (j >= 0 && numbers[j] > value) {
            numbers[j + 1] = numbers[j];
            j--;
        }
        numbers[j + 1] = value;
    }
}

int main(void) {
    int numbers[MAX_SIZE];
    int size, choice, i;

    printf("Choose a sorting algorithm:\n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("Enter your choice (1-3): ");
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Invalid choice. Please run the program again and choose 1, 2, or 3.\n");
        return 1;
    }

    printf("Enter the array size (1-%d): ", MAX_SIZE);
    if (scanf("%d", &size) != 1 || size < 1 || size > MAX_SIZE) {
        printf("Invalid size. Please enter a number from 1 to %d.\n", MAX_SIZE);
        return 1;
    }

    printf("Enter %d integer value(s), separated by spaces: ", size);
    for (i = 0; i < size; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            return 1;
        }
    }

    printf("\nArray before sorting: ");
    printArray(numbers, size);

    if (choice == 1) {
        bubbleSort(numbers, size);
    } else if (choice == 2) {
        selectionSort(numbers, size);
    } else {
        insertionSort(numbers, size);
    }

    printf("Array after sorting:  ");
    printArray(numbers, size);

    return 0;
}
