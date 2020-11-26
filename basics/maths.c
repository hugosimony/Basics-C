/*
 * Some basics maths functions
*/

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
unsigned long power_of_two(unsigned char n){
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