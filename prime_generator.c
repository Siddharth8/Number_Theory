/*=============================================================================
This is a simple implementation of the Sieve of Sundaram algorithm to generate 
Prime Numbers Between a Given Range.
=============================================================================*/
/******************************************************************************
    Copyright (C) 2015 Siddharth Agrawal
******************************************************************************/
#include <stdio.h>
int main()
{
    int array_size, i, j, x;
    int number_Primes = 0;
    printf("Input a positive integer to find all the prime numbers up to and including that number: ");
    scanf("%d", &array_size);
    int n = array_size / 2;
    int size;
    /* array to start off with that will eventually get
     all the composite numbers removed and the remaining
     ones output to the screen */

    int isPrime[array_size + 1];
    int arePrime = 0;

    for (i = 0; i < n; ++i)
    {
        isPrime[i] = i;
    }

    for (i = 1; i < n; i++)
    {
        for (j = i; j <= (n - i) / (2 * i + 1); j++)
        {
            isPrime[i + j + 2 * i * j] = 0;
        }
    }

    if (array_size > 2)
    {
        isPrime[arePrime++] = 2;
    }

    for (i = 1; i < n; i++)
    {
        if (isPrime[i] != 0)
        {
            isPrime[arePrime++] = i * 2 + 1;
        }
    }

    size = sizeof isPrime / sizeof(int);//total size of array/size of array data type

    for (x = 0; x <= size; x++)
    {
        if (isPrime[x] != 0)
        {
            printf("%d \t", isPrime[x]);
            number_Primes++;// the counter of the number of primes found
        } else
        {
            break;
        }
    }

    printf("\nNumber of Primes: %d", number_Primes);
    return 0;
}

