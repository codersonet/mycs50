#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(string key);

int main(int argc, string argv[])
{
    // check for one command line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // validate that the key consists of only alphabets
    string key = argv[1];

    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    // validate that the key has 26 characters
    if (strlen(key) != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // validate that the key has no repeated characters
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (toupper(key[i]) == toupper(key[j]))
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }
    encrypt(key);
    return 0;
}

void encrypt(string key)
{
    // create a new string to hold the ciphertext
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // iterate over each character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // check if the character is an alphabet
        if (isalpha(plaintext[i]))
        {
            // determine the index of the character in the alphabet
            int index = toupper(plaintext[i]) - 'A';

            // substitute the character using the key
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(key[index]));
            }
            else
            {
                printf("%c", tolower(key[index]));
            }
        }
        else
        {
            // if the character is not an alphabet, print it as is
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
