#include <stdio.h>

// Function to compute (base^exponent) % mod using modular exponentiation
long long mod_exp(long long base, long long exponent, long long mod) {
    long long result = 1;
    base = base % mod;
    
    while (exponent > 0) {
        // If exponent is odd, multiply base with result
        if (exponent % 2 == 1) {
            result = (result * base) % mod;
        }
        // Exponent must be even now
        exponent = exponent >> 1; // Equivalent to exponent / 2
        base = (base * base) % mod;
    }
    return result;
}

// Function to check if a number is prime
int is_prime(long long n) {
    if (n <= 1) return 0;
    if (n <= 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

// Function to apply Fermat's Little Theorem
void fermat_little_theorem(long long a, long long p) {
    if (is_prime(p)) {
        if (a % p == 0) {
            printf("%lld is divisible by %lld, so Fermat's Little Theorem does not apply.\n", a, p);
        } else {
            long long result = mod_exp(a, p - 1, p);
            printf("According to Fermat's Little Theorem: %lld^%lld mod %lld = %lld\n", a, p - 1, p, result);
        }
    } else {
        printf("%lld is not a prime number.\n", p);
    }
}

int main() {
    long long a, p;
    
    // Input the base and prime number
    printf("Enter the base (a): ");
    scanf("%lld", &a);
    printf("Enter the prime number (p): ");
    scanf("%lld", &p);
    
    // Apply Fermat's Little Theorem
    fermat_little_theorem(a, p);

    return 0;
}
