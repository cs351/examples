/*
 * Demonstrates:
 * - "returning" values via pointers
 */

#include <stdio.h>
#include <math.h>

int quad_roots(double a, double b, double c,
               double *pr1, double *pr2) {
    double discr = b*b - 4*a*c;
    if (discr < 0)
        return 0; /* no real roots */
    *pr1 = (-b + sqrt(discr)) / 2*a;
    *pr2 = (-b - sqrt(discr)) / 2*a;
    return 1;
}

int main() {
    double x0, x1;
    if (quad_roots(1, 3, 2, &x0, &x1))
        printf("root 1 = %0.1f; root 2 = %0.1f\n", x0, x1);
    return 0;
}
