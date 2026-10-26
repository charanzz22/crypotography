#include <stdio.h>
#include <string.h>
#define MAX 256

void swap(unsigned char *a, unsigned char *b) {
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

// RC4 Key Scheduling Algorithm
void KSA(unsigned char S[], unsigned char key[], int keyLength) {
    int i, j = 0;
    for (i = 0; i < MAX; i++)
        S[i] = i;
    for (i = 0; i < MAX; i++) {
        j = (j + S[i] + key[i % keyLength]) % MAX;
        swap(&S[i], &S[j]);
    }
}

// RC4 Pseudo-Random Generation Algorithm
void PRGA(unsigned char S[], unsigned char data[], int length) {
    int i = 0;
    int j = 0;
    for (int k = 0; k < length; k++) {
        i = (i + 1) % MAX;
        j = (j + S[i]) % MAX;
        swap(&S[i], &S[j]);
        int t = (S[i] + S[j]) % MAX;
        unsigned char keyStream = S[t];
        data[k] ^= keyStream;
    }
}

void printHex(unsigned char data[], int length) {
    for (int i = 0; i < length; i++)
        printf("%02X ", data[i]);
    printf("\n");
}

int main() {
    unsigned char plaintext[] = "GITAMUNIVERSITYISDEEMEDTOBEUNIVERSITY";
    unsigned char key[] = "LOKESH";
    unsigned char S[MAX];
    int length = strlen((char *)plaintext);
    int keyLength = strlen((char *)key);
    unsigned char ciphertext[length + 1];
    unsigned char decrypted[length + 1];
    // ---------------- ENCRYPTION ----------------
    memcpy(ciphertext, plaintext, length);
    KSA(S, key, keyLength);
    PRGA(S, ciphertext, length);
    printf("========== RC4 ==========\n");
    printf("Plaintext : %s\n", plaintext);
    printf("Key       : %s\n", key);
    printf("\nCiphertext (Hex): ");
    printHex(ciphertext, length);
    // ---------------- DECRYPTION ----------------
    // RC4 encryption and decryption use exactly the same operation.
    memcpy(decrypted, ciphertext, length);
    KSA(S, key, keyLength);
    PRGA(S, decrypted, length);
    decrypted[length] = '\0';
    printf("\nDecrypted Text: %s\n", decrypted);
    return 0;
}
