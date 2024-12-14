#include <stdio.h>

int main() {
    char ch;

    // Lowercase letters
    for(ch = 'a'; ch <= 'z'; ch++) {
        printf("%c: %d\n", ch, ch);
    }

    printf("\n");

    // Uppercase letters
    for(ch = 'A'; ch <= 'Z'; ch++) {
        printf("%c: %d\n", ch, ch);
    }

    return 0;
}
