#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void railfence_encipher(int key, const char *plaintext, char *ciphertext);
void railfence_decipher(int key, const char *ciphertext, char *plaintext);

int main() {
    /* allocate some space for results of enciphering/deciphering */
    char plaintext[256];
    int key;

    /* read input from the user */
    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0'; // remove newline character

    printf("Enter the key: ");
    scanf("%d", &key);

    char *ciphertext = malloc(strlen(plaintext) + 1);
    char *result = malloc(strlen(plaintext) + 1);

    /* the following lines do all the enciphering and deciphering */
    railfence_encipher(key, plaintext, ciphertext);
    railfence_decipher(key, ciphertext, result);

    /* print our results */
    printf("-->original:   %s\n-->ciphertext: %s\n-->plaintext:  %s\n",
            plaintext, ciphertext, result);

    free(ciphertext);
    free(result);

    return 0;
}

/*******************************************************************
void railfence_encipher(int key, const char *plaintext, char *ciphertext)
- Uses railfence transposition cipher to encipher some text.
- takes a key, string of plaintext, result returned in ciphertext.
- ciphertext should be an array the same size as plaintext.
- The key is the number of rails to use
*******************************************************************/
void railfence_encipher(int key, const char *plaintext, char *ciphertext) {
    int line, i, skip, length = strlen(plaintext), j = 0, k = 0;

    for (line = 0; line < key - 1; line++) {
        skip = 2 * (key - line - 1);
        k = 0;
        for (i = line; i < length;) {
            ciphertext[j++] = plaintext[i];
            if ((line == 0) || (k % 2 == 0))
                i += skip;
            else
                i += 2 * (key - 1) - skip;
            k++;
        }
    }
    for (i = line; i < length; i += 2 * (key - 1))
        ciphertext[j++] = plaintext[i];

    ciphertext[j] = '\0'; /* Null terminate */
}

/*******************************************************************
void railfence_decipher(int key, const char *ciphertext, char *plaintext)
- Uses railfence transposition cipher to decipher some text.
- takes a key, string of ciphertext, result returned in plaintext.
- plaintext should be an array the same size as plaintext.
- The key is the number of rails to use
*******************************************************************/
void railfence_decipher(int key, const char *ciphertext, char *plaintext) {
    int i, length = strlen(ciphertext), skip, line, j, k = 0;

    for (line = 0; line < key - 1; line++) {
        skip = 2 * (key - line - 1);
        j = 0;
        for (i = line; i < length;) {
            plaintext[i] = ciphertext[k++];
            if ((line == 0) || (j % 2 == 0))
                i += skip;
            else
                i += 2 * (key - 1) - skip;
            j++;
        }
    }
    for (i = line; i < length; i += 2 * (key - 1))
        plaintext[i] = ciphertext[k++];

    plaintext[length] = '\0'; /* Null terminate */
}
