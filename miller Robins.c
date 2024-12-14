#include <stdio.h>
#include <stdlib.h>

// Function to perform modular exponentiation
long long mod_exp(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        exponent = exponent >> 1; // Equivalent to exponent / 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to perform the Miller-Rabin primality test
int miller_rabin(long long n, int k) {
    // Seed the random number generator with a fixed value
    srand(12345); // Fixed seed for reproducibility

    // Base cases
    if (n <= 1 || n == 4) return 0;
    if (n == 2 || n == 3) return 1;

    // Find d such that n = 2^r * d + 1
    long long d = n - 1;
    int r = 0;
    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    // Witness loop
    for (int i = 0; i < k; i++) {
        long long a = 2 + rand() % (n - 4); // Randomly select a
        long long x = mod_exp(a, d, n);

        if (x == 1 || x == n - 1) continue;

        int flag = 0;
        for (int j = 0; j < r - 1; j++) {
            x = mod_exp(x, 2, n);
            if (x == n - 1) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) return 0; // Composite
    }
    return 1; // Probably prime
}

int main() {
    long long n;
    int k;

    // Input the number and the number of iterations
    printf("Enter a number to test for primality: ");
    scanf("%lld", &n);
    printf("Enter the number of iterations (recommended: 5-10): ");
    scanf("%d", &k);

    // Apply the Miller-Rabin primality test
    if (miller_rabin(n, k)) {
        printf("%lld is probably prime.\n", n);
    } else {
        printf("%lld is composite.\n", n);
    }

    return 0;
}
