#include <stdio.h>
#include <cs50.h>

void print(int n, char ch);


int main(void)
{
    //Asking the height of the block. It should be grater than 0 and not higher than 8
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while(n > 8 || n < 1);
    
    for (int i = 1; i < n + 1; i++)
    {
        print( n - i, ' ');
        print(i, '#');
        printf("  ");

        print(i, '#');
        //print( n - i, ' ');
        printf("\n");

    }
    
}

void print(int n, char ch)
{
    for (int j = 0; j < n; j++)
    {
        printf("%c", ch);
    }
}