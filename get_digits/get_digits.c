/* Calculates the number of decimal digits */

int get_digits(long n)
{
    int digits = 0;
    if(n == 0)
        return 1;
    while(n)
    {
        digits++;
        n /= 10;
    }
    return digits;
}
