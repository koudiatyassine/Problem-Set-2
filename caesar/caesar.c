#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// Function prototype
void caesarCipher(string plaintext, int key);

int main(int argc, string argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Convert the key from string to integer
    int key = atoi(argv[1]);

    // Prompt user for plaintext input
    string plaintext = get_string("plaintext: ");

    // Encrypt and print ciphertext
    printf("ciphertext: ");
    caesarCipher(plaintext, key);
    printf("\n");

    return 0;
}

// Function to perform Caesar cipher encryption
void caesarCipher(string plaintext, int key)
{
    // Iterate over each character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char encryptedChar = plaintext[i];

        // Encrypt uppercase letters
        if (isupper(encryptedChar))
        {
            encryptedChar = 'A' + (encryptedChar - 'A' + key) % 26;
        }
        // Encrypt lowercase letters
        else if (islower(encryptedChar))
        {
            encryptedChar = 'a' + (encryptedChar - 'a' + key) % 26;
        }

        // Print the character as ciphertext
        printf("%c", encryptedChar);
    }
}
