#include <stdio.h>
#include <string.h>
void getOrder(char key[], int order[]) {
    int i, j;
    int n = strlen(key);

    for (i = 0; i < n; i++)
        order[i] = 0;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (key[j] < key[i])
                order[i]++;
            else if (key[j] == key[i] && j < i)
                order[i]++;
        }
    }
}
void encrypt(char text[], char key[], char result[]) {
    int order[20];
    int rows, cols, i, j, k = 0;
    char matrix[100][20];
    cols = strlen(key);
    rows = (strlen(text) + cols - 1) / cols;
    getOrder(key, order);
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (k < strlen(text))
                matrix[i][j] = text[k++];
            else
                matrix[i][j] = 'X';
        }
    }
    k = 0;
    for (int n = 0; n < cols; n++) {
        for (j = 0; j < cols; j++) {
            if (order[j] == n) {
                for (i = 0; i < rows; i++)
                    result[k++] = matrix[i][j];
            }
        }
    }

    result[k] = '\0';
}
void decrypt(char text[], char key[], char result[]) {
    int order[20];
    int rows, cols, i, j, k = 0;
    char matrix[100][20];
    cols = strlen(key);
    rows = strlen(text) / cols;
    getOrder(key, order);
    for (int n = 0; n < cols; n++) {
        for (j = 0; j < cols; j++) {
            if (order[j] == n) {
                for (i = 0; i < rows; i++)
                    matrix[i][j] = text[k++];
            }
        }
    }
    k = 0;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++)
            result[k++] = matrix[i][j];
    }

    result[k] = '\0';
}
int main() {
    char plaintext[100];
    char key1[20], key2[20];
    char temp[100], ciphertext[100], decrypted1[100], decrypted[100];
    printf("Enter plaintext: ");
    scanf("%s", plaintext);
    printf("Enter first key: ");
    scanf("%s", key1);
    printf("Enter second key: ");
    scanf("%s", key2);
    encrypt(plaintext, key1, temp);
    encrypt(temp, key2, ciphertext);
    printf("\nEncrypted message: %s\n", ciphertext);
    decrypt(ciphertext, key2, decrypted1);
    decrypt(decrypted1, key1, decrypted);
    printf("Decrypted message: %s\n", decrypted);
    return 0;
}