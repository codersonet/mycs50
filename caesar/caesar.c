#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

void cipher(string key);        // Function prototype for cypher function

int main(int argc, string argv[])           // Main function that takes command line arguments
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");        // Check if the number of command line arguments is not equal to 2
        return 1;
    }
    // Check if the key is a valid integer
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Call the cipher function with the provided key
    cipher(argv[1]);
    return 0;
}

// Function to perform the Caesar cipher encryption
void cipher(string key)
{
    // Convert the key from string to integer
    int k = atoi(key);
    // Get the plaintext input from the user
    string plaintext = get_string("plaintext: ");
    // Print the ciphertext label
    printf("ciphertext: ");

    // Loop through each character in the plaintext
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // Check if the character is an uppercase letter
        if (isupper(plaintext[i]))
        {
            printf("%c", ((plaintext[i] - 65 + k) % 26) + 65);
        }
        else if (islower(plaintext[i]))
        {
            printf("%c", ((plaintext[i] - 97 + k) % 26) + 97);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    // Print a newline character after the ciphertext
    printf("\n");
}
