#include <stdio.h>
long long modularExponentiation(int base, int expr, int modd) {
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
    int B, N, M;
    // Input base, exponent, and modulus
    printf("Enter the base B: ");
    if (scanf("%d", &B) != 1) {
        printf("Invalid input. Please enter an integer for the base.\n");
        return 1;
    }
    printf("Enter the exponent N: ");
    if (scanf("%d", &N) != 1) {
        printf("Invalid input. Please enter an integer for the exponent.\n");
        return 1;
    }
    printf("Enter the modulus M: ");
    if (scanf("%d", &M) != 1) {
        printf("Invalid input. Please enter an integer for the modulus.\n");
        return 1;
    }
    if(M<=1||N<0||B<0)
    {
       printf("Invalid input B>=0, N>=0 and M>1.\n");
       return 1;
    }
    long long result = modularExponentiation(B, N, M);
    printf("Result %lld\n", result);

    return 0;
}
