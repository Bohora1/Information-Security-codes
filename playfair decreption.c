#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

// Function to convert all characters of a string to lowercase
void toLowerCase(char plain[], int ps)
{
    int i;
    for (i = 0; i < ps; i++) {
        if (plain[i] >= 'A' && plain[i] <= 'Z')
            plain[i] += 32;
    }
}

// Function to remove spaces from the string
int removeSpaces(char* str, int len)
{
    int i, count = 0;
    for (i = 0; i < len; i++) {
        if (str[i] != ' ')
            str[count++] = str[i];
    }
    str[count] = '\0';
    return count;
}

// Function to generate the 5x5 key square
void generateKeyTable(char keystr[], int ks, char keyT[5][5])
{
    int i, j, k, *dicty;
    dicty = (int*)calloc(26, sizeof(int));

    for (i = 0; i < ks; i++) {
        if (keystr[i] != 'j')
            dicty[keystr[i] - 'a'] = 2;
    }
    dicty['j' - 'a'] = 1;

    i = 0;
    j = 0;
    for (k = 0; k < ks; k++) {
        if (dicty[keystr[k] - 'a'] == 2) {
            dicty[keystr[k] - 'a'] -= 1;
            keyT[i][j] = keystr[k];
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
    for (k = 0; k < 26; k++) {
        if (dicty[k] == 0) {
            keyT[i][j] = (char)(k + 'a');
            j++;
            if (j == 5) {
                i++;
                j = 0;
            }
        }
    }
    free(dicty);
}

// Function to search for the characters of a digraph in the key square and return their position
void search(char keyT[5][5], char a, char b, int arr[])
{
    int i, j;
    if (a == 'j') a = 'i';
    if (b == 'j') b = 'i';

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (keyT[i][j] == a) {
                arr[0] = i;
                arr[1] = j;
            }
            if (keyT[i][j] == b) {
                arr[2] = i;
                arr[3] = j;
            }
        }
    }
}

// Function to decrypt the ciphertext
void decrypt(char str[], char keyT[5][5], int ps)
{
    int i, a[4];
    for (i = 0; i < ps; i += 2) {
        search(keyT, str[i], str[i + 1], a);
        if (a[0] == a[2]) {
            str[i] = keyT[a[0]][(a[1] - 1 + 5) % 5];
            str[i + 1] = keyT[a[0]][(a[3] - 1 + 5) % 5];
        } else if (a[1] == a[3]) {
            str[i] = keyT[(a[0] - 1 + 5) % 5][a[1]];
            str[i + 1] = keyT[(a[2] - 1 + 5) % 5][a[1]];
        } else {
            str[i] = keyT[a[0]][a[3]];
            str[i + 1] = keyT[a[2]][a[1]];
        }
    }
}

// Function to decrypt using the Playfair Cipher
void PlayfairDeCrypt(char str[], char keystr[])
{
    char keyT[5][5];
    int ps = strlen(str);
    int ks = strlen(keystr);

    ks = removeSpaces(keystr, ks);
    toLowerCase(str, ps);
    ps = removeSpaces(str, ps);
    generateKeyTable(keystr, ks, keyT);
    decrypt(str, keyT, ps);

    // Plain text printed in lower case letters
    printf("Plain text: %s\n", str);
}

// Driver code
int main()
{
    char str[SIZE], keystr[SIZE];

    // Key used - to be entered in lower case letters
    printf("Enter the key: ");
    scanf("%[^\n]s", keystr);
    printf("Key text: %s\n", keystr);

    printf("Enter the ciphertext: ");
    scanf("\n");
    scanf("%[^\n]s", str);
    printf("Cipher text: %s\n", str);

    // Calling the PlayfairDeCrypt function
    PlayfairDeCrypt(str, keystr);

    return 0;
}
