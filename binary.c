/*=============================================================================
This is an implementation of binary algorithm to find the GCD of two numbers.
Note that it only uses shifts to multiply or divide by a power of 2 and so
avoids doing expensive multiplication and division operations, which matters
when we are dealing with large multiple-precision numbers.
=============================================================================*/
/******************************************************************************
    Copyright (C) 2015 Siddharth Agrawal
******************************************************************************/
#include<stdio.h>
unsigned long binary_gcd(unsigned long u, unsigned long v);
int main()
{
    unsigned long a, b, c;
    printf("Enter the value of a & b\n");
    scanf("%lu  %lu", &a, &b);
    c = binary_gcd(a, b);
    printf("The gcd is: %lu\n", c);
    return 0;
}

unsigned long binary_gcd(unsigned long u, unsigned long v)
{
    if (u == v) return u;
    if (u == 0) return v;
    if (v == 0) return u;

    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return binary_gcd(u >> 1, v);
        else // both u and v are even
            return binary_gcd(u >> 1, v >> 1) << 1;
    }

    if (~v & 1) // u is odd, v is even
        return binary_gcd(u, v >> 1);

    if (u > v)
        return binary_gcd((u - v) >> 1, v);

    return binary_gcd((v - u) >> 1, u);
}

