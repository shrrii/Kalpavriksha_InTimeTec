#include <stdio.h>
long long modularExponentiation(long long base, long long expr, long long modd) {
   if(expr==0)
    return 1;
    base=base%modd;
    long long answer=modularExponentiation(base,expr/2,modd);
    answer=answer*answer;
    answer=answer%modd;
    if(expr%2==1)
    {
        answer=answer*base;
        answer=answer%modd;
    }
    return answer;
}
int main() {
    long long B, N, M;

    // Input base, exponent, and modulus
    printf("Enter the base B: ");
    scanf("%lld", &B);
    printf("Enter the exponent N: ");
    scanf("%lld", &N);
    printf("Enter the modulus M: ");
    scanf("%lld", &M);

    if (M == 0) {
        printf("Modulus cannot be zero.\n");
        return 1;
    }
    long long result = modularExponentiation(B, N, M);
    printf("Result %lld\n", result);

    return 0;
}
