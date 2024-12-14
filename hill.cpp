#include<stdio.h>
#include<math.h>
#include<string.h>

char plain[20], plain2[20], encrypted[20], x[1], y[1], z[1];
char characters[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'}, ciphertext[3], plaintext[3];
int i, j, k, w, key2[3][3], key3[3][3];
int number[3], cipher[3], choice, choice2, determinant;
char temp;

void encryption3x3(char ch1[], char ch2[], char ch3[]);
void decryption3x3(char ch1[], char ch2[], char ch3[]);
void key_inverse_3x3(int key[3][3], int inverse[3][3]);

int mod26(int num) {
    return (num % 26 + 26) % 26;
}

int modInverse(int a, int m) {
    a = a % m;
    for (int x = 1; x < m; x++) {
        if ((a * x) % m == 1)
            return x;
    }
    return 1;
}

void encryption3x3(char ch1[], char ch2[], char ch3[]) {
    char plain[4] = {};
    plain[3] = '\0';

    strcat(plain, ch1);
    strcat(plain, ch2);
    strcat(plain, ch3);
    printf("\n-----Three-pair character text is:-----\n");
    puts(plain);

    number[0] = 0;
    number[1] = 0;
    number[2] = 0;
    cipher[0] = 0;
    cipher[1] = 0;
    cipher[2] = 0;
    ciphertext[0] = 0;
    ciphertext[1] = 0;
    ciphertext[2] = 0;

    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 25; j++) {
            if (plain[i] == characters[j]) {
                number[i] = j;
            }
        }
    }

    printf("\nAlphabetical ordered number text will be-\n");
    for (k = 0; k <= 2; k++)
        printf("%d  ", number[k]);

    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
            cipher[i] = cipher[i] + (key2[i][j] * number[j]);
        }

        cipher[i] = cipher[i] % 26;

        for (k = 0; k <= 25; k++) {
            if (cipher[i] == k)
                ciphertext[i] = characters[k];
        }
    }

    printf("\nGenerated Cipher text in alphabetical ordered number text will be-\n");
    for (i = 0; i <= 2; i++)
        printf("%d ", cipher[i]);

    printf("\nCipher text of the pair will be: ");
    puts(ciphertext);
}

void key_inverse_3x3(int key[3][3], int inverse[3][3]) {
    int det = 0;
    for (i = 0; i < 3; i++)
        det = det + (key[0][i] * (key[1][(i + 1) % 3] * key[2][(i + 2) % 3] - key[1][(i + 2) % 3] * key[2][(i + 1) % 3]));

    int detModInverse = modInverse(det, 26);

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            inverse[j][i] = ((key[(i + 1) % 3][(j + 1) % 3] * key[(i + 2) % 3][(j + 2) % 3]) -
                            (key[(i + 1) % 3][(j + 2) % 3] * key[(i + 2) % 3][(j + 1) % 3]));
            inverse[j][i] = mod26(inverse[j][i] * detModInverse);
        }
    }
}

void decryption3x3(char ch1[], char ch2[], char ch3[]) {
    char encrypt[4] = {};
    encrypt[3] = '\0';

    strcat(encrypt, ch1);
    strcat(encrypt, ch2);
    strcat(encrypt, ch3);
    printf("\n-----Three-pair encrypted character text is:-----\n");
    puts(encrypt);

    number[0] = 0;
    number[1] = 0;
    number[2] = 0;
    cipher[0] = 0;
    cipher[1] = 0;
    cipher[2] = 0;
    plaintext[0] = 0;
    plaintext[1] = 0;
    plaintext[2] = 0;

    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 25; j++) {
            if (encrypt[i] == characters[j]) {
                number[i] = j;
            }
        }
    }

    printf("\nAlphabetical ordered number text will be-\n");
    for (k = 0; k <= 2; k++)
        printf("%d  ", number[k]);

    for (i = 0; i <= 2; i++) {
        for (j = 0; j <= 2; j++) {
            cipher[i] = cipher[i] + (key3[i][j] * number[j]);
        }

        cipher[i] = cipher[i] % 26;

        for (k = 0; k <= 25; k++) {
            if (cipher[i] == k)
                plaintext[i] = characters[k];
        }
    }

    printf("\nGenerated Plain text in alphabetical ordered number text will be-\n");
    for (i = 0; i <= 2; i++)
        printf("%d ", cipher[i]);

    printf("\nPlain text of the pair will be: ");
    puts(plaintext);
}

main() {
    printf("Hill Cipher");
    do {
        printf("\nMAIN MENU");
        printf("\n1. 2x2 encryption/decryption \t2. 3x3 encryption \t3. 3x3 decryption \t4. EXIT");
        printf("\nEnter your choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // Implement your 2x2 encryption/decryption here (already provided in your initial code)
                break;

            case 2:
                printf("\n--------3x3 Hill Cipher-----------");
                printf("\nEnter the plain text: ");
                scanf("%s", &plain2);

                printf("\nEnter the 3*3 Key Matrix-");
                for (i = 0; i <= 2; i++) {
                    for (j = 0; j <= 2; j++) {
                        scanf("%d", &key2[i][j]);
                    }
                }
                printf("\nKey is:\n");
                for (i = 0; i <= 2; i++) {
                    for (j = 0; j <= 2; j++) {
                        printf("%d  ", key2[i][j]);
                    }
                    printf("\n");
                }

                printf("\n-------------------Encrypting each three-character pair of plain text-----------------------\n\n");

                for (w = 0; plain2[w] != '\0';) {
                    x[0] = plain2[w];
                    x[1] = '\0';

                    y[0] = plain2[w + 1];
                    y[1] = '\0';

                    z[0] = plain2[w + 2];
                    z[1] = '\0';

                    encryption3x3(x, y, z);
                    w = w + 3;
                }
                break;

            case 3:
                printf("\n--------3x3 Hill Cipher Decryption-----------");
                printf("\nEnter the cipher text: ");
                scanf("%s", &encrypted);

                printf("\nEnter the 3*3 Key Matrix-");
                for (i = 0; i <= 2; i++) {
                    for (j = 0; j <= 2; j++) {
                        scanf("%d", &key2[i][j]);
                    }
                }
                printf("\nEntered Key is:\n");
                for (i = 0; i <= 2; i++) {
                    for (j = 0; j <= 2; j++) {
                        printf("%d  ", key2[i][j]);
                    }
                    printf("\n");
                }

                key_inverse_3x3(key2, key3);

                printf("\n-------------------Decrypting each three-character pair of cipher text-----------------------\n\n");

                for (w = 0; encrypted[w] != '\0';) {
                    x[0] = encrypted[w];
                    x[1] = '\0';

                    y[0] = encrypted[w + 1];
                    y[1] = '\0';

                    z[0] = encrypted[w + 2];
                    z[1] = '\0';

                    decryption3x3(x, y, z);
                    w = w + 3;
                }
                break;
        }
    } while (choice != 4);
}
