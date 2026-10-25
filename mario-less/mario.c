#include <cs50.h>
#include <stdio.h>

// declaring rows fucntion prototype
void rows(int height);
int height;

// defining a main function, and calling rows

int main(void)
{
    // Prompt the user for the pyramid's height
    do
    {
        height = get_int("Enter the height for the pyramid: ");
    }
    while (height < 1);

    // Print a pyramid of that height
    for (int i = 0; i < height; i++)
    {
        // Print row of bricks
        rows(i + 1);
    }
}

// defining a function called rows
void rows(int bricks)
{
    // Print spaces
    for (int i = 0; i < height - bricks; i++)
    {
        printf(" ");
    }
    // Print bricks
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
