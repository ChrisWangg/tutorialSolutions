#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool hasTwoSum(int *numbers, int target, int sizeOfArray);
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No arguments passed.\n");
        return 1;
    }

    // Allocate memory for the integer array
    int *numbers = malloc((argc - 2) * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Convert arguments to integers and store them in the array
    for (int i = 1; i < argc - 1; i++) {
        numbers[i - 1] = atoi(argv[i]);
    }

    // Two Sum
    printf("Two sum result %d\n", hasTwoSum(numbers, atoi(argv[argc - 1]), argc - 2));
    // Free the allocated memory
    free(numbers);

    return 0;
}
bool hasTwoSum(int *numbers, int target, int sizeOfArray) {
    for (int i = 0; i < sizeOfArray; i++) {
        for (int j = i + 1; j < sizeOfArray; j++) {
            if (numbers[i] + numbers[j] == target) {
                return true;
            }
        }
    }
    return false;
}
