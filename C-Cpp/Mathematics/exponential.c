/**
 * @author Eduardo Costa de Souza
 */

#include <stdio.h>
#include <math.h>

double exp_c(double x) {
    // The method used to calculate the exp is:
    //     exp(x) = 1 + 2 * x / (2 - x + x * x / (6 + x * x / (10 + x * x / (14 + x * x / (...)))))
    //
    // This method converges faster than most methods, and it was described in:
    //     Continued Fractions, Vol. 1: Convergence Theory. From: Lisa Lorentzen and Haakon Waadeland.

    double xsqr = x * x;
    int n = (10 + (int) x) * 4 - 2;
    __float128 sum = n + 4;
    for ( ; n != 2; n -= 4)
        sum = n + xsqr / sum;

    return 1 + 2 * x / (2 - x + xsqr / sum);
}
