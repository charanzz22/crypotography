#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[100];
    char encrypted[100], decrypted[100];
    int i, j = 0, k;

    printf("Enter the message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    scanf("%s", key);

    k = strlen(key);

    // Encryption
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            encrypted[i] = ((toupper(text[i]) - 'A' +
                            toupper(key[j % k]) - 'A') % 26) + 'A';
            j++;
        } else {
            encrypted[i] = text[i];
        }
    }
    encrypted[i] = '\0';

    printf("Encrypted message: %s", encrypted);

    // Decryption
    j = 0;
    for (i = 0; encrypted[i] != '\0'; i++) {
        if (isalpha(encrypted[i])) {
            decrypted[i] = ((encrypted[i] - 'A' -
                            (toupper(key[j % k]) - 'A') + 26) % 26) + 'A';
            j++;
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[i] = '\0';

    printf("Decrypted message: %s", decrypted);

    return 0;
}
