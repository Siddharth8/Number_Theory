/*=============================================================================
This is a simple implementation of the Euclidean algorithm. It is an efficient method to compute the greatest common divisor (gcd) of two integers.
=============================================================================*/
/******************************************************************************
    Copyright (C) 2015 Siddharth Agrawal
******************************************************************************/
#include<stdio.h>
long euclid_gcd(long a, long b);
int main()
{
    long a, b, c;
    printf("Enter the value of a & b\n");
    scanf("%ld  %ld", &a, &b);
    c = euclid_gcd(a, b);
    printf("The gcd is: %ld\n",c);
    return 0;
}

long euclid_gcd(long a, long b)
{
    long r;
    if (a < 0) a = -a;
    if (b < 0) b = -b;

    if (b > a)
    { /* swap */
        r = b; b = a; a = r;
    }

    while (b > 0) {
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

