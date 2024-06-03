#include <stdio.h>
#include <stdlib.h>

void solveHanoi(int numDisks, char fromRod, char toRod, char otherRod);
int main(void) {
    int n;
    printf("How many disks: n? = ");
    scanf("%d", &n);
    solveHanoi(n, 'A', 'C', 'B');

    return 0;
}
void solveHanoi(int numDisks, char fromRod, char toRod, char otherRod) {
    if (numDisks == 1) {
        printf("Move disk from Rod %c to Rod %c\n", fromRod, toRod);
        return;
    }
    solveHanoi(numDisks - 1, fromRod, otherRod, toRod);
    printf("Move disk from Rod %c to Rod %c\n", fromRod, toRod);
    solveHanoi(numDisks - 1, otherRod, toRod, fromRod);
}
