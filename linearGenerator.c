#include <stdio.h>

#define IA 16807
#define IM 2147483647
#define AM (1.0/IM)
#define IQ 127773
#define IR 2836
#define MASK 123459876

float ram0(long *idum)
{
    long k;
    float ans;

    *idum ^= MASK;
    k=(*idum)/IQ;
    *idum=IA*(*idum-k*IQ)-IR*k;
    if (*idum < 0) *idum += IM;
    ans=AM*(*idum);
    *idum ^= MASK;
    return ans;
}

int main(void)
{
    long seed = -1;
    int n = 1000;
    FILE *fp;

    fp = fopen("result.txt", "w");
    if (fp == NULL) {
        printf("Error.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        float valor = ram0(&seed);
        fprintf(fp, "%d %f\n", i, valor);
    }

    fclose(fp);
    return 0;
}
