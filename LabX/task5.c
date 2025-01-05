#include <stdio.h>

// Function prototype
// Takes pointers to three integers and returns their sum.
int add(int *a, int *b, int *c);

int main() {
    int num1, num2, num3, result;

    // Input values
    printf("Enter three integers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    // Call add function with references
    result = add(&num1, &num2, &num3);

    // Output result
    printf("The sum of %d, %d, and %d is: %d\n", num1, num2, num3, result);

    return 0;
}

// Function definition
int add(int *a, int *b, int *c) {
    return *a + *b + *c;
}
