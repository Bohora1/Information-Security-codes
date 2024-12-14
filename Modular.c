#include <stdio.h>

// Function for modular addition
int mod_add(int a, int b, int mod) {
    return (a + b) % mod;
}

// Function for modular subtraction
int mod_sub(int a, int b, int mod) {
    return (a - b + mod) % mod;
}

// Function for modular multiplication
int mod_mul(int a, int b, int mod) {
    return (a * b) % mod;
}

// Function for modular exponentiation
int mod_exp(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;

    while (exp > 0) {
        // If exp is odd, multiply base with the result
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }

        // exp must be even now
        exp = exp >> 1; // exp = exp / 2
        base = (base * base) % mod; // Change base to base^2
    }

    return result;
}

// Main function
int main() {
    int a, b, mod;

    // Taking inputs from the user
    printf("Enter the value of a: ");
    scanf("%d", &a);
    printf("Enter the value of b: ");
    scanf("%d", &b);
    printf("Enter the value of mod: ");
    scanf("%d", &mod);

    // Displaying results
    printf("Modular addition: (%d + %d) %% %d = %d\n", a, b, mod, mod_add(a, b, mod));
    printf("Modular subtraction: (%d - %d) %% %d = %d\n", a, b, mod, mod_sub(a, b, mod));
    printf("Modular multiplication: (%d * %d) %% %d = %d\n", a, b, mod, mod_mul(a, b, mod));
    printf("Modular exponentiation: (%d ^ %d) %% %d = %d\n", a, b, mod, mod_exp(a, b, mod));

    return 0;
}
