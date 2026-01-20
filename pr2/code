#include <stdio.h>

int main() {
    int a, b, choice, i;

    // -------------------- INPUT SECTION --------------------
    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    // -------------------- FOR LOOP SECTION --------------------
    // Loop runs menu 3 times
    for (i = 1; i <= 3; i++) {
        printf("\n--- Arithmetic Operations Menu (Loop %d) ---\n", i);
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // -------------------- SWITCH CASE SECTION --------------------
        switch (choice) {
            case 1:
                printf("Addition: %d + %d = %d\n", a, b, a + b);
                break;

            case 2:
                printf("Subtraction: %d - %d = %d\n", a, b, a - b);
                break;

            case 3:
                printf("Multiplication: %d * %d = %d\n", a, b, a * b);
                break;

            case 4:
                // -------------------- IF ELSE SECTION --------------------
                if (b != 0) {
                    printf("Division: %d / %d = %d\n", a, b, a / b);
                } else {
                    printf("Error: Division by zero is not allowed.\n");
                }
                break;

            case 5:
                // -------------------- IF ELSE SECTION --------------------
                if (b != 0) {
                    printf("Modulus: %d %% %d = %d\n", a, b, a % b);
                } else {
                    printf("Error: Modulus by zero is not allowed.\n");
                }
                break;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}

