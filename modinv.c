/*=============================================================================
This code is an adaptation of the extended Euclidean algorithm from Knuth
avoiding negative integers. It computes the multiplicative inverse of
u modulo v, and returns either the inverse as  a positive integer less than v,
or zero if no inverse exists.
=============================================================================*/
/******************************************************************************
    Copyright (C) 2015 Siddharth Agrawal
******************************************************************************/
#include<stdio.h>
unsigned int modinv(unsigned int u, unsigned int v);
int main()
{
    unsigned int a, b, c;
    printf("Enter the value of a & b\n");
    scanf("%u  %u", &a, &b);
    c = modinv(a, b);
    printf("The multiplicative inverse of a modulo b is: %u\n", c);
    return 0;
}

unsigned int modinv(unsigned int u, unsigned int v)
{
    unsigned int inv, u1, u3, v1, v3, t1, t3, q;
    int iter;
    u1 = 1;
    u3 = u;
    v1 = 0;
    v3 = v;
    iter = 1;
    while (v3 != 0)
    {
        /* Divide and "Subtract" */
        q = u3 / v3;
        t3 = u3 % v3;
        t1 = u1 + q * v1;
        /* Swap */
        u1 = v1; v1 = t1; u3 = v3; v3 = t3;
        iter = -iter;
    }
    if (u3 != 1)
        return 0;   /* No inverse exists */

    if (iter < 0)
        inv = v - u1;
    else
        inv = u1;
    return inv;
}

