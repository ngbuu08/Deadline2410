#include <stdio.h>
#include "EquationIO.h"
#include "Equation.h"

void SolutionPrint(int n, double x1, double x2, double x3, double x4) {
    switch (n) {
    case NoSolution:
        printf_s("Phuong trinh vo nghiem.\n");
        break;
    case Undetermined:
        printf_s("Phuong trinh vo so nghiem.\n");
        break;
    case 1:
        printf_s("Phuong trinh co 1 nghiem: x = %g\n", x1);
        break;
    case 2:
        printf_s("Phuong trinh co 2 nghiem: x1 = %g, x2 = %g\n", x1, x2);
        break;
    case 3:
        printf_s("Phuong trinh co 3 nghiem: x1 = %g, x2 = %g, x3 = %g\n",
            x1, x2, x3);
        break;
    case 4:
        printf_s("Phuong trinh co 4 nghiem: x1 = %g, x2 = %g, x3 = %g, x4 = %g\n",
            x1, x2, x3, x4);
        break;
    }
}

void EquaDisplay1(double a, double b) {
    printf_s("%gx + %g = 0\n", a, b);
}

void EquaDisplay2(double a, double b, double c) {
    printf_s("%gx^2 + %gx + %g = 0\n", a, b, c);
}

void EquaBiquadDisplay(double a, double b, double c) {
    printf_s("%gx^4 + %gx^2 + %g = 0\n", a, b, c);
}

void EquationInput1(double* a, double* b) {
    printf_s("Nhap a, b: ");
    scanf_s("%lf %lf", a, b);
}

void EquationInput2(double* a, double* b, double* c) {
    printf_s("Nhap a, b, c: ");
    scanf_s("%lf %lf %lf", a, b, c);
}