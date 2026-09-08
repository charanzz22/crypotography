#include <stdio.h>
#include <string.h>

int main() {
    char text[100], encrypted[100], decrypted[100];
    char rail[10][100];
    int rails, len, i, j, row, dir, index;

    printf("Enter the message: ");
    scanf("%s", text);

    printf("Enter number of rails: ");
    scanf("%d", &rails);

    len = strlen(text);

    // Initialize rail matrix
    for (i = 0; i < rails; i++)
        for (j = 0; j < len; j++)
            rail[i][j] = '\n';
    row = 0;
    dir = 1;

    for (i = 0; i < len; i++) {
        rail[row][i] = text[i];

        if (row == 0)
            dir = 1;
        else if (row == rails - 1)
            dir = -1;

        row += dir;
    }

    index = 0;

    for (i = 0; i < rails; i++) {
        for (j = 0; j < len; j++) {
            if (rail[i][j] != '\n')
                encrypted[index++] = rail[i][j];
        }
    }

    encrypted[index] = '\0';

    printf("Encrypted message: %s\n", encrypted);
    for (i = 0; i < rails; i++)
        for (j = 0; j < len; j++)
            rail[i][j] = '\n';

    row = 0;
    dir = 1;

    // Mark positions
    for (i = 0; i < len; i++) {
        rail[row][i] = '*';

        if (row == 0)
            dir = 1;
        else if (row == rails - 1)
            dir = -1;

        row += dir;
    }

    // Fill encrypted characters
    index = 0;

    for (i = 0; i < rails; i++) {
        for (j = 0; j < len; j++) {
            if (rail[i][j] == '*' && index < len)
                rail[i][j] = encrypted[index++];
        }
    }

    // Read in zigzag order
    row = 0;
    dir = 1;

    for (i = 0; i < len; i++) {
        decrypted[i] = rail[row][i];

        if (row == 0)
            dir = 1;
        else if (row == rails - 1)
            dir = -1;

        row += dir;
    }

    decrypted[len] = '\0';

    printf("Decrypted message: %s\n", decrypted);

    return 0;
}