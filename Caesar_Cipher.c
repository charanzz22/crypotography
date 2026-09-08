#include <stdio.h>
#include <ctype.h>

int main() {
    char text[100], encrypted[100], decrypted[100];
    int key, i;

    printf("Enter the message: ");
    fgets(text, sizeof(text), stdin);

    printf("Enter the key: ");
    scanf("%d", &key);

    // Encryption
    for (i = 0; text[i] != '\0'; i++) {
        if (isupper(text[i]))
            encrypted[i] = (text[i] - 'A' + key) % 26 + 'A';
        else if (islower(text[i]))
            encrypted[i] = (text[i] - 'a' + key) % 26 + 'a';
        else
            encrypted[i] = text[i];
    }
    encrypted[i] = '\0';

    printf("Encrypted message: %s", encrypted);

    // Decryption
    for (i = 0; encrypted[i] != '\0'; i++) {
        if (isupper(encrypted[i]))
            decrypted[i] = (encrypted[i] - 'A' - key + 26) % 26 + 'A';
        else if (islower(encrypted[i]))
            decrypted[i] = (encrypted[i] - 'a' - key + 26) % 26 + 'a';
        else
            decrypted[i] = encrypted[i];
    }
    decrypted[i] = '\0';

    printf("Decrypted message: %s", decrypted);

    return 0;
}
