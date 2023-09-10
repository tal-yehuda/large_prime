#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define max INT_MAX
#define no  2

int sqrt_int(int i){
    if (i <= 1) return 1;
    int a = 0;
    int b = i;
    int m = i / 2;

    while (a != m){
        if (m <= i / m) a = m;
        else b = m;
        m = a + (b - a) / 2;
    }
    return m;
}

int *primes = NULL;
int len = 0;
int cap = 0;

void add_prime(int p){
    if (len == cap){
        cap = (cap + 1) * 2;
        primes = realloc(primes, cap * sizeof(int));
        if (primes == NULL) exit(1);
    }
    primes[len++] = p;
}

int check_prime(int n){
    for (int i = 0; i < len; i++)
        if (n % primes[i] == 0) return 0;
    return 1;
}

int main(void){
    int check = sqrt_int(max);
    for (int n = 2; n <= check; n++)
        if (check_prime(n)) add_prime(n);


    int n = max;
    int done = 0;
    while ((done += check_prime(n)) != no) n -= 1;


    printf("%d", n);
    return 0;
}
