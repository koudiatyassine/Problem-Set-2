#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

// Function prototypes
bool is_valid_key(string key);
string encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    // Check if there is exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Check if the key is valid
    string key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 unique alphabetic characters.\n");
        return 1;
    }

    // Get plaintext from user
    string plaintext = get_string("plaintext:  ");

    // Encrypt the plaintext
    string ciphertext = encrypt(plaintext, key);

    // Output the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Function to check if the key is valid
bool is_valid_key(string key)
{
    int length = strlen(key);
    if (length != 26)
    {
        return false;
    }

    bool letters[26] = {false};

    for (int i = 0; i < length; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (letters[index])
        {
            return false;
        }
        letters[index] = true;
    }

    return true;
}

// Function to encrypt the plaintext using the key
string encrypt(string plaintext, string key)
{
    int n = strlen(plaintext);

    for (int i = 0; i < n; i++)
    {
        if (isalpha(plaintext[i]))
        {
            bool is_upper = isupper(plaintext[i]);
            int index = toupper(plaintext[i]) - 'A';

            // Preserve case
            plaintext[i] = is_upper ? toupper(key[index]) : tolower(key[index]);
        }
    }

    return plaintext;
}
