/*
 * Some basics maths functions
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*****************************************
// Fibonnaci
unsigned long fibo(unsigned long n){
    if(n == 0)
        return 0;
    unsigned long a = 1;
    unsigned long b = 1;
    unsigned long c = 1;
    for (unsigned long i = 2; i<n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

//*****************************************
// Power of two (linear)
unsigned long power_of_two(unsigned long n){
    return (((unsigned long) 1)<<n);
}

//*****************************************
// Factorial
unsigned long facto(unsigned long n){
    unsigned long x = 1;
    for (unsigned long i = 0; i < n; i++)
        x *= n-i;
    return x;
}

//*****************************************
// Square Root
unsigned long isqrt(unsigned long n){
    unsigned long r = n;
    while (r*r > n){
        r = (r + n / r);
        r = r / 2;
    }  
    return r;
}

//*****************************************
// Digit Count
unsigned char digit_count(unsigned long n){
    if(n == 0)
        return (unsigned char) 1;
    unsigned char x = 0;
    unsigned long y = 1;
    while(y<=n){
        x++;
        y*=10;
    }
    return x;
}

//*****************************************
// Digit Sum
unsigned char digit_sum(unsigned long n){
    if(n == 0)
        return (unsigned char) 0;
    unsigned char x = 0;
    unsigned long y = 1;
    while(y<=n){
        x+=n/y;
        y*=10;
    }
    return x;
}

//*****************************************
// Divisor Sum -> Perfect Number

// Divisor Sum
unsigned long divisor_sum(unsigned long n){
    if(n == 1)
        return 0;
    unsigned long x = 0;
    unsigned long y = 0;
    for(unsigned long i = 2; i*i <= n; i++){
        if(n % i == 0){
            x = x+i;
            y = n/i;
            if(i != y)
                x += y;
        }
    }
    return x+1;
}

// With pointer
unsigned long sum_of_divisors(unsigned long n, size_t *count)
{
    unsigned long sum = 1;
    *count = 1;
    for(unsigned long i = 2; i<n/2+1; i++){
        if(n % i == 0){
            *count = (*count + 1);
            sum += i;
        }
    }
    return sum;
}

// Perfect Number
int is_perfect_number(unsigned long n) {
    if(n == divisor_sum(n))
        return 1;
    return 0;
}

//*****************************************
// Usage

// Helpeur
void print_help(){
    printf("--------- Usage ---------\n");
    printf(" -> maths fibo x\n");
    printf(" -> maths 2power x\n");
    printf(" -> maths facto x\n");
    printf(" -> maths sqrt x\n");
    printf(" -> maths digit_count x\n");
    printf(" -> maths digit_sum x\n");
    printf(" -> maths divisor_sum x\n");
    printf(" -> maths perfect x\n");
    printf(" -> maths help\n");
    printf(" (x is an unsigned long)\n");
    printf("-------------------------\n");
}

// Main function
int main(int argc, char *argv[]) {
    if(argc != 3){
        print_help();
        return 0;
    }
    char *ptr;
    long x = strtol(argv[2], &ptr, 10);
    if(x < 0) x *= -1;
    if(strcmp(argv[1], "fibo") == 0){
        printf("Fibonnaci(%lu) = %lu.\n", x, fibo(x));
        return 1;
    }
    if(strcmp(argv[1], "2power") == 0){
        printf("2^%lu = %lu.\n", x, power_of_two(x));
        return 1;
    }
    if(strcmp(argv[1], "facto") == 0){
        printf("%lu! = %lu.\n", x, facto(x));
        return 1;
    }
    if(strcmp(argv[1], "sqrt") == 0){
        printf("Integral Square Root of %lu = %lu.\n", x, isqrt(x));
        return 1;
    }
    if(strcmp(argv[1], "digit_count") == 0){
        printf("%lu has %u digits.\n", x, digit_count(x));
        return 1;
    }
    if(strcmp(argv[1], "digit_sum") == 0){
        printf("The digits sum of %lu is %u.\n", x, digit_sum(x));
        return 1;
    }
    if(strcmp(argv[1], "divisor_sum") == 0){
        printf("The sum of the divisors of %lu is %lu.\n", x, divisor_sum(x));
        return 1;
    }
    if(strcmp(argv[1], "perfect") == 0){
        printf("%lu is %sa perfect number !\n", x, is_perfect_number(x) == 1 ? "" : "not ");
        return 1;
    }
    return 0;
}