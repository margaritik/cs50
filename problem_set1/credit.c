#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long card = get_long("Number: ");
    long card1 = card;
    int sum = 0;
    int num = 0;
    

    
    // calculation checksum
    do
    {
        int b = card % 10;
        card /= 10;
        num++;
        
        int a = card % 10;
        a *= 2;
        if (a > 9)
        {
            int c = a % 10 + a / 10;
            a = c;
        }
        
        sum += a;
        sum += b;
        if (card > 0)
        {
            num++;
            card /= 10;
        }
        
        //printf("a: %i, b: %i, sum: %i, num: %i\n", b, a, sum, num);
    }
    while (card > 0);
    
    int fst = card1 / pow(10, num - 1);
    int sec = card1 / pow(10, num - 2);
    
    if (sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    
    // AMEX  15-digits, starts from 34 and 37
    else if (((num == 15) & (sec == 34)) || (sec== 37))
    {
        printf("AMEX\n");
    }
    
    //MASTER 16-digits, starts from 51-55
    else if ((num == 16) & (sec > 50) & (sec < 56))
    {
        printf("MASTERCARD\n");
    }
    
    //VISA 13 and 16-digits, starts from 4
    else if ((num == 13|| num == 16) & (fst % 10 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
    //printf("Sum: %i, num: %i, first digits: %i, %i\n", sum, num, fst, sec);
}