#ifndef _EQUATION_H_
#define _EQUATION_H_

#include <math.h>

#define NoSolution    0
#define Undetermined -1
#define EPS 1e-12

static inline int EquaDeg1(double a, double b, double* x) {
    if (fabs(a) < EPS) {
        if (fabs(b) < EPS)
            return Undetermined;
        return NoSolution;
    }
    *x = -b / a;
    return 1;
}

static inline int EquaDeg2(double a, double b, double c, double* x, double* y) {
    double delta, s;
    int n;

    if (fabs(a) < EPS) {
        n = EquaDeg1(b, c, x);
        if (n == 1)
            *y = *x;
        return n;
    }
    delta = b * b - 4 * a * c;
    if (delta < 0)
        return NoSolution;
    if (fabs(delta) < EPS) {
        *x = *y = -b / (2 * a);
        return 1;
    }
    s = sqrt(delta);
    *x = (-b - s) / (2 * a);
    *y = (-b + s) / (2 * a);
    return 2;
}

static inline int EquaBiquad(double a, double b, double c,
    double* x1, double* x2, double* x3, double* x4) {
    double t[2] = { 0, 0 };
    double res[4];
    double r;
    int nt, n = 0, i;

    nt = EquaDeg2(a, b, c, &t[0], &t[1]);
    if (nt == Undetermined)
        return Undetermined;
    if (nt == NoSolution)
        return NoSolution;

    for (i = 0; i < nt; i++) {
        if (t[i] < 0) continue;
        if (fabs(t[i]) < EPS) {
            res[n++] = 0;
        }
        else {
            r = sqrt(t[i]);
            res[n++] = -r;
            res[n++] = r;
        }
    }
    if (n == 0)
        return NoSolution;

    *x1 = res[0];
    if (n > 1) *x2 = res[1];
    if (n > 2) *x3 = res[2];
    if (n > 3) *x4 = res[3];
    return n;
}

#endif