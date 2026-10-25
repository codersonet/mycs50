#include <cs50.h>
#include <stdio.h>

void rows(int bricks);
int height;

int main(void)
{
    do
    {
        height = get_int("Enter the height of the pyramid: ");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        rows(i + 1);
    }
}

void rows(int bricks)
{
    for (int i = 0; i < height - bricks; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    for (int i = 0; i < 2; i++)
    {
        printf(" ");
    }
    for (int i = 0; i < bricks; i++)
    {
        printf("#");
    }
    printf("\n");
}
