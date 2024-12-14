#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Function prototypes
void inputPolynomial(int poly[], int degree);
void printPolynomial(int poly[], int degree);
void addPolynomials(int poly1[], int poly2[], int result[], int degree1, int degree2);
void subtractPolynomials(int poly1[], int poly2[], int result[], int degree1, int degree2);
void multiplyPolynomials(int poly1[], int poly2[], int result[], int degree1, int degree2);

int main() {
    int degree1, degree2;
    int poly1[MAX], poly2[MAX], result[MAX * 2] = {0};  // Result can be up to degree1 + degree2

    printf("Enter the degree of the first polynomial: ");
    scanf("%d", &degree1);
    printf("Enter the coefficients of the first polynomial (from lowest to highest degree):\n");
    inputPolynomial(poly1, degree1);

    printf("Enter the degree of the second polynomial: ");
    scanf("%d", &degree2);
    printf("Enter the coefficients of the second polynomial (from lowest to highest degree):\n");
    inputPolynomial(poly2, degree2);

    printf("\nFirst Polynomial: ");
    printPolynomial(poly1, degree1);

    printf("\nSecond Polynomial: ");
    printPolynomial(poly2, degree2);

    printf("\nAddition Result: ");
    addPolynomials(poly1, poly2, result, degree1, degree2);
    printPolynomial(result, (degree1 > degree2 ? degree1 : degree2));

    printf("\nSubtraction Result: ");
    subtractPolynomials(poly1, poly2, result, degree1, degree2);
    printPolynomial(result, (degree1 > degree2 ? degree1 : degree2));

    printf("\nMultiplication Result: ");
    multiplyPolynomials(poly1, poly2, result, degree1, degree2);
    printPolynomial(result, (degree1 + degree2));

    return 0;
}

void inputPolynomial(int poly[], int degree) {
    for (int i = 0; i <= degree; i++) {
        printf("Coefficient of x^%d: ", i);
        scanf("%d", &poly[i]);
    }
}

void printPolynomial(int poly[], int degree) {
    int firstTerm = 1;  // Flag to check if it's the first term to avoid printing + for the first term

    for (int i = degree; i >= 0; i--) {
        if (poly[i] != 0) {  // Print only if the coefficient is not zero
            if (!firstTerm && poly[i] > 0) {
                printf("+");
            }
            if (i == 0 || poly[i] != 1) {
                printf("%d", poly[i]);
            } else if (i > 0) {
                printf("1");
            }
            if (i > 0) {
                printf("x");
                if (i > 1) {
                    printf("^%d", i);
                }
            }
            firstTerm = 0;  // After the first term, set flag to 0
        }
    }
    if (firstTerm) {
        printf("0");  // If no non-zero terms were printed, print 0
    }
    printf("\n");
}

void addPolynomials(int poly1[], int poly2[], int result[], int degree1, int degree2) {
    int maxDegree = (degree1 > degree2 ? degree1 : degree2);
    for (int i = 0; i <= maxDegree; i++) {
        result[i] = (i <= degree1 ? poly1[i] : 0) + (i <= degree2 ? poly2[i] : 0);
    }
}

void subtractPolynomials(int poly1[], int poly2[], int result[], int degree1, int degree2) {
    int maxDegree = (degree1 > degree2 ? degree1 : degree2);
    for (int i = 0; i <= maxDegree; i++) {
        result[i] = (i <= degree1 ? poly1[i] : 0) - (i <= degree2 ? poly2[i] : 0);
    }
}

void multiplyPolynomials(int poly1[], int poly2[], int result[], int degree1, int degree2) {
    int resultDegree = degree1 + degree2;
    for (int i = 0; i <= degree1; i++) {
        for (int j = 0; j <= degree2; j++) {
            result[i + j] += poly1[i] * poly2[j];
        }
    }
}
