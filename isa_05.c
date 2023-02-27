#include <stdio.h>
#include <complex.h>
int main() {
    double real = 0,
    imag = 1;
    double complex z    = CMPLX(real, imag);
    printf("z = %.1f% + .1fi\n",creal(z), cimag(z));
}