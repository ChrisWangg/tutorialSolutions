#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char *string);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("No arguments passed. \n");
        return 1;
    }
    // Check is Palindrome
    printf("Is it a palindrome %d\n", isPalindrome(argv[1]));
}

bool isPalindrome(char *string) {
    int l = 0;
    int r = strlen(string) - 1;

    while (l < r) {
        if (string[l] != string[r]) {
            return false;
        }
        l++;
        r--;
    }
    return true;
}
