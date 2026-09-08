#include <stdio.h>

int modInverse(int a) {
    int i;
    for (i = 1; i < 26; i++) {
        if ((a * i) % 26 == 1)
            return i;
    }
    return -1;
}

int main() {
    int key[2][2], inv[2][2];
    int det, invDet;
    char text[100], encrypted[100], decrypted[100];
    int i, a, b;

    printf("Enter 2x2 key matrix:\n");
    for (i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &key[i][j]);

    printf("Enter plaintext: ");
    scanf("%s", text);

    // Calculate determinant
    det = key[0][0] * key[1][1] -
          key[0][1] * key[1][0];

    det = (det % 26 + 26) % 26;

    // Find modular inverse of determinant
    invDet = modInverse(det);

    if (invDet == -1) {
        printf("Invalid key matrix!");
        return 0;
    }

    // Inverse key matrix
    inv[0][0] = key[1][1] * invDet % 26;
    inv[0][1] = -key[0][1] * invDet % 26;
    inv[1][0] = -key[1][0] * invDet % 26;
    inv[1][1] = key[0][0] * invDet % 26;

    for (i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            inv[i][j] = (inv[i][j] + 26) % 26;

    // Encryption
    for (i = 0; text[i] != '\0'; i += 2) {
        a = text[i] - 'A';
        b = text[i + 1] - 'A';

        encrypted[i] =
            (key[0][0] * a + key[0][1] * b) % 26 + 'A';

        encrypted[i + 1] =
            (key[1][0] * a + key[1][1] * b) % 26 + 'A';
    }

    encrypted[i] = '\0';

    printf("Encrypted text: %s\n", encrypted);

    // Decryption
    for (i = 0; encrypted[i] != '\0'; i += 2) {
        a = encrypted[i] - 'A';
        b = encrypted[i + 1] - 'A';

        decrypted[i] =
            (inv[0][0] * a + inv[0][1] * b) % 26 + 'A';

        decrypted[i + 1] =
            (inv[1][0] * a + inv[1][1] * b) % 26 + 'A';
    }

    decrypted[i] = '\0';

    printf("Decrypted text: %s\n", decrypted);

    return 0;
}