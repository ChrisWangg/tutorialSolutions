#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define RESET_COLOR   "\x1b[0m"
#define RED_COLOR     "\x1b[31m"
#define GREEN_COLOR   "\x1b[32m"

struct TestCase {
        int *array;
        int size;
        int targetSum;
        bool expectedResult;
    };

void test3sum() {
    // Define test cases
    struct TestCase testCases[] = {
        { (int[]){1, 2, 3, 4, 5}, 5, 10, true },
        { (int[]){-1, -2, -3, -4, -5}, 5, -6, true },
        { (int[]){1, 2, 3, 4, 5}, 5, 15, false },
        { (int[]){5, 1, 0, -1, -5}, 5, 0, true },
        { (int[]){}, 0, 0, false },
        { (int[]){3, 7, 1, 2, 8, 4, 5}, 7, 20, true },
        { (int[]){3, 7, 1, 2, 8, 4, 5}, 7, 21, false },
        { (int[]){1, 1, 1, 1, 1}, 5, 3, true },
        { (int[]){1, 1, 1, 1, 1}, 5, 4, false },
        { (int[]){1, 1, 1, 1, 1}, 5, 5, false },
        { (int[]){1, 1, 1, 1, 1}, 5, 6, false },
        { (int[]){100, 200, 300, 400, 500}, 5, 1000, true },
        { (int[]){100, 200, 300, 400, 500}, 5, 50, false },
        { (int[]){-10, -20, -30, -40, -50}, 5, -60, true },
        { (int[]){-10, -20, -30, -40, -50}, 5, -100, true },
        { (int[]){-10, -20, -30, -40, -50}, 5, -110, true },
        { (int[]){1, 2}, 2, 3, false },
        { (int[]){1, 2, 3}, 3, 6, true },
        { (int[]){1, 2, 3}, 3, 7, false },
        { (int[]){0, 0, 0}, 3, 0, true },
        { (int[]){0, 0, 0}, 3, 1, false },
        { (int[]){INT_MAX, INT_MAX, INT_MAX}, 3, INT_MAX, false }, // Potential overflow test
        { (int[]){INT_MAX, INT_MAX, -INT_MAX}, 3, INT_MAX, true },
        { (int[]){1, 2, 4, 5, 6, 7}, 6, 13, true },
        { (int[]){1, 2, 4, 5, 6, 7}, 6, 14, true },
        { (int[]){1, 2, 4, 5, 6, 7}, 6, 21, false },
        { (int[]){2, 4, 6}, 3, 12, true },
        { (int[]){-1, 0, 1, 2, -1, -4}, 6, 0, true },
        { (int[]){-2, 0, 1, 1, 2}, 5, 0, true },
        { (int[]){-4, -1, -1, 0, 1, 2}, 6, -1, true },
        { (int[]){3, 0, -2, -1, 1, 2}, 6, 0, true },
        { (int[]){-1, -1, -1, 2, 2}, 5, 0, true },
    };

    int numTestCases = sizeof(testCases) / sizeof(testCases[0]);

    int passedTests = 0;

    for (int i = 0; i < numTestCases; i++) {
        bool result = threeSum(testCases[i].array, testCases[i].size, testCases[i].targetSum);
        if (result == testCases[i].expectedResult) {
            printf(GREEN_COLOR "Test %d passed.\n" RESET_COLOR, i + 1);
            passedTests++;
        } else {
            printf(RED_COLOR "Test %d failed.\n" RESET_COLOR, i + 1);
            printf("  Input array: ");
            for (int j = 0; j < testCases[i].size; j++) {
                printf("%d ", testCases[i].array[j]);
            }
            printf("\n  Target sum: %d\n", testCases[i].targetSum);
            printf("  Expected result: %s\n", testCases[i].expectedResult ? "true" : "false");
            printf("  Actual result: %s\n", result ? "true" : "false");
        }
    }

    printf("\nTotal tests passed: %d/%d\n", passedTests, numTestCases);

}
    