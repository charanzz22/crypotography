#include <stdio.h>
#include <string.h>
#include <ctype.h>

char matrix[5][5];

void generateMatrix(char key[]) {
    int used[26] = {0};
    int i, j, k = 0;
    char ch;

    used['J' - 'A'] = 1;   // Combine I and J

    // Put key letters
    for (i = 0; key[i] != '\0'; i++) {
        ch = toupper(key[i]);

        if (ch == 'J')
            ch = 'I';

        if (ch >= 'A' && ch <= 'Z' && !used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }

    // Put remaining letters
    for (ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[k / 5][k % 5] = ch;
            used[ch - 'A'] = 1;
            k++;
        }
    }
}

void findPosition(char ch, int *row, int *col) {
    int i, j;

    if (ch == 'J')
        ch = 'I';

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void process(char text[], char result[], int encrypt) {
    int i, r1, c1, r2, c2;
    char a, b;

    for (i = 0; text[i] != '\0'; i += 2) {

        a = text[i];
        b = text[i + 1];

        findPosition(a, &r1, &c1);
        findPosition(b, &r2, &c2);

        // Same row
        if (r1 == r2) {
            if (encrypt) {
                result[i] = matrix[r1][(c1 + 1) % 5];
                result[i + 1] = matrix[r2][(c2 + 1) % 5];
            } else {
                result[i] = matrix[r1][(c1 + 4) % 5];
                result[i + 1] = matrix[r2][(c2 + 4) % 5];
            }
        }

        // Same column
        else if (c1 == c2) {
            if (encrypt) {
                result[i] = matrix[(r1 + 1) % 5][c1];
                result[i + 1] = matrix[(r2 + 1) % 5][c2];
            } else {
                result[i] = matrix[(r1 + 4) % 5][c1];
                result[i + 1] = matrix[(r2 + 4) % 5][c2];
            }
        }

        // Rectangle rule
        else {
            result[i] = matrix[r1][c2];
            result[i + 1] = matrix[r2][c1];
        }
    }

    result[i] = '\0';
}

int main() {
    char key[100], plaintext[100];
    char prepared[100], encrypted[100], decrypted[100];
    int i, j, k = 0;

    printf("Enter key: ");
    scanf("%s", key);

    printf("Enter plaintext: ");
    scanf("%s", plaintext);

    // Prepare plaintext
    for (i = 0; plaintext[i] != '\0'; i++) {
        char ch = toupper(plaintext[i]);

        if (ch == 'J')
            ch = 'I';

        prepared[k++] = ch;
    }

    prepared[k] = '\0';

    // Add X if length is odd
    if (k % 2 != 0) {
        prepared[k++] = 'X';
        prepared[k] = '\0';
    }

    // Generate matrix
    generateMatrix(key);

    printf("\nPlayfair Matrix:\n");

    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }

    // Encryption
    process(prepared, encrypted, 1);

    printf("\nEncrypted text: %s\n", encrypted);

    // Decryption
    process(encrypted, decrypted, 0);

    printf("Decrypted text: %s\n", decrypted);

    return 0;
}