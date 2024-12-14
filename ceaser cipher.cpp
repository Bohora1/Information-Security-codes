#include <stdio.h>
#include <conio.h>

void encrypt(char text[], int k) {
    int i;
    char c;
    for (i = 0; text[i] != '\0'; i++) {
        c = text[i];
        if (c >= 'a' && c <= 'z') {
            c = c + k;
            if (c > 'z') {
                c = c - 'z' + 'a' - 1;
            }
            text[i] = c;
        } else if (c >= 'A' && c <= 'Z') {
            c = c + k;
            if (c > 'Z') {
                c = c - 'Z' + 'A' - 1;
            }
            text[i] = c;
        }
    }
    printf("Encrypted message: %s\n", text);
}

void decrypt(char text[], int k) {
    int i;
    char c;
    for (i = 0; text[i] != '\0'; i++) {
        c = text[i];
        if (c >= 'a' && c <= 'z') {
            c = c - k;
            if (c < 'a') {
                c = c + 'z' - 'a' + 1;
            }
            text[i] = c;
        } else if (c >= 'A' && c <= 'Z') {
            c = c - k;
            if (c < 'A') {
                c = c + 'Z' - 'A' + 1;
            }
            text[i] = c;
        }
    }
    printf("Decrypted message: %s\n", text);
}

int main() {
    char text[100];
    int k;
    int choice;

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);
    getchar(); // To consume the newline character left by scanf

    if (choice == 1) {
        printf("Enter a plaintext: \n");
        gets(text);
        printf("Enter key: ");
        scanf("%d", &k);
        encrypt(text, k);
    } else if (choice == 2) {
        printf("Enter an encrypted message: \n");
        gets(text);
        printf("Enter key: ");
        scanf("%d", &k);
        decrypt(text, k);
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
