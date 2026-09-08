#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char text[100], key[27];
    char encrypted[100], decrypted[100];
    int i;

    // Standard alphabet
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Input
    printf("Enter the plaintext: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key (26 letters): ");
    scanf("%s", key);

    // Encryption
    for (i = 0; text[i] != '\0'; i++) {
        if (isalpha(text[i])) {
            char ch = toupper(text[i]);
            encrypted[i] = key[ch - 'A'];
        } else {
            encrypted[i] = text[i];
        }
    }
    encrypted[i] = '\0';

    printf("\nEncrypted text: %s", encrypted);

    // Decryption
    for (i = 0; encrypted[i] != '\0'; i++) {
        if (isalpha(encrypted[i])) {
            char ch = toupper(encrypted[i]);

            for (int j = 0; j < 26; j++) {
                if (key[j] == ch) {
                    decrypted[i] = alphabet[j];
                    break;
                }
            }
        } else {
            decrypted[i] = encrypted[i];
        }
    }
    decrypted[i] = '\0';

    printf("Decrypted text: %s", decrypted);

    return 0;
}