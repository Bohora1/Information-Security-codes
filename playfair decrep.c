#include <stdio.h>
#include <string.h>
#include <ctype.h>

void decryptPlayfair(char ciphertext[], char key[]);

int main() {
    char ciphertext[100];
    char key[100];

    printf("Enter the ciphertext: ");
    gets(ciphertext);

    printf("Enter the key: ");
    gets(key);

    decryptPlayfair(ciphertext, key);

    return 0;
}

void decryptPlayfair(char ciphertext[], char key[]) {
    int i, j, k, row1, row2, col1, col2, flag = -1;
    int lenkey, templen, numkey[100], cipherkey[5][5];
    int lenCiphertext = strlen(ciphertext);

    // Convert key to uppercase and remove spaces
    for (i = 0, j = 0; i < strlen(key); i++) {
        if (key[i] != ' ') {
            key[j] = toupper(key[i]);
            j++;
        }
    }
    key[j] = '\0';

    // Storing key in terms of ASCII
    k = 0;
    for (i = 0; i < strlen(key) + 26; i++) {
        if (i < strlen(key)) {
            if (key[i] == 'J') flag = 8;  // Considering 'J' as 'I'
            numkey[i] = key[i] - 'A';
        } else {
            if (k != 9 && k != flag) {  // Skip 'I' if 'J' is in key
                numkey[i] = k;
            }
            k++;
        }
    }
    templen = i;

    // Remove repeated characters in key
    lenkey = templen;
    for (i = 0; i < lenkey; i++) {
        for (j = i + 1; j < lenkey;) {
            if (numkey[i] == numkey[j]) {
                for (k = j; k < lenkey; k++) {
                    numkey[k] = numkey[k + 1];
                }
                lenkey--;
            } else {
                j++;
            }
        }
    }

    // Arrange key in 5x5 grid
    k = 0;
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            cipherkey[i][j] = numkey[k];
            k++;
        }
    }

    // Decryption process
    for (k = 0; k < lenCiphertext; k += 2) {
        for (i = 0; i < 5; i++) {
            for (j = 0; j < 5; j++) {
                if (ciphertext[k] - 'A' == cipherkey[i][j]) {
                    row1 = i;
                    col1 = j;
                }
                if (ciphertext[k + 1] - 'A' == cipherkey[i][j]) {
                    row2 = i;
                    col2 = j;
                }
            }
        }

        if (row1 == row2) {
            col1 = (col1 - 1 + 5) % 5;
            col2 = (col2 - 1 + 5) % 5;
            ciphertext[k] = cipherkey[row1][col1] + 'A';
            ciphertext[k + 1] = cipherkey[row2][col2] + 'A';
        } else if (col1 == col2) {
            row1 = (row1 - 1 + 5) % 5;
            row2 = (row2 - 1 + 5) % 5;
            ciphertext[k] = cipherkey[row1][col1] + 'A';
            ciphertext[k + 1] = cipherkey[row2][col2] + 'A';
        } else {
            ciphertext[k] = cipherkey[row1][col2] + 'A';
            ciphertext[k + 1] = cipherkey[row2][col1] + 'A';
        }
    }

    // Output the decrypted text
    printf("Decrypted text: ");
    for (i = 0; i < lenCiphertext; i++) {
        if (ciphertext[i] != 'X')  // Remove extra 'X' added during encryption
            printf("%c", ciphertext[i]);
    }
    printf("\n");
}
