#include <math.h>
#include <stdio.h>

/* Calculates the number of decimal digits */
int get_decimal_digit_num(long n)
{
    int digits = 0;
    if (n == 0)
        return 1;
    while (n)
    {
        digits++;
        n /= 10;
    }
    return digits;
}

/* Gets the numeric value of a decimal digit */
int get_decimal_bit_value(int n, int bit)
{
    if (n < 0)
    {
        n = -n;
    }

    if (get_decimal_digit_num(n) < bit || bit <= 0)
    {
        return -1;
    }
    else if (bit == 1)
    {
        return n % 10;
    }
    else
    {
        n %= (int)pow(10.0, bit );

        return n / (int)pow(10.0, bit - 1);
    }
    return -1;
}

int sample(void)
{
    printf("%d \n", get_decimal_bit_value(-12345, 0));
    printf("%d \n", get_decimal_bit_value(-12345, 1));
    printf("%d \n", get_decimal_bit_value(-12345, 2));
    printf("%d \n", get_decimal_bit_value(-12345, 3));
    printf("%d \n", get_decimal_bit_value(-12345, 4));
    printf("%d \n", get_decimal_bit_value(-12345, 5));
    printf("%d \n", get_decimal_bit_value(-12345, 6));

    printf("%d \n", get_decimal_bit_value(0, 1));
    printf("%d \n", get_decimal_bit_value(1, 1));

    printf("%d \n", get_decimal_bit_value(9,1));
    printf("%d \n", get_decimal_bit_value(12, 1));
    printf("%d \n", get_decimal_bit_value(12, 2));
    printf("%d \n", get_decimal_bit_value(12, 3));

    printf("%d \n", get_decimal_bit_value(12345, 0));
    printf("%d \n", get_decimal_bit_value(12345, 1));
    printf("%d \n", get_decimal_bit_value(12345, 2));
    printf("%d \n", get_decimal_bit_value(12345, 3));
    printf("%d \n", get_decimal_bit_value(12345, 4));
    printf("%d \n", get_decimal_bit_value(12345, 5));
    printf("%d \n", get_decimal_bit_value(12345, 6));

    return 0;
}