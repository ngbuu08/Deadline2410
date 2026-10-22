#include <stdio.h>
#include "EquationIO.h"
#include "Equation.h"

int main() {
    int choice, n, ch;
    double a, b, c, x1, x2, x3, x4;

    do {
        printf_s("\n===== GIAI PHUONG TRINH =====\n");
        printf_s("1. Phuong trinh bac 1  (ax + b = 0)\n");
        printf_s("2. Phuong trinh bac 2  (ax^2 + bx + c = 0)\n");
        printf_s("3. Phuong trinh trung phuong (ax^4 + bx^2 + c = 0)\n");
        printf_s("0. Thoat\n");
        printf_s("Chon: ");
        if (scanf_s("%d", &choice) != 1) {
            while ((ch = getchar()) != '\n' && ch != EOF);
            choice = -1;
        }

        a = b = c = x1 = x2 = x3 = x4 = 0;

        switch (choice) {
        case 1:
            EquationInput1(&a, &b);
            EquaDisplay1(a, b);
            n = EquaDeg1(a, b, &x1);
            SolutionPrint(n, x1, 0, 0, 0);
            break;
        case 2:
            EquationInput2(&a, &b, &c);
            EquaDisplay2(a, b, c);
            n = EquaDeg2(a, b, c, &x1, &x2);
            SolutionPrint(n, x1, x2, 0, 0);
            break;
        case 3:
            EquationInput2(&a, &b, &c);
            EquaBiquadDisplay(a, b, c);
            n = EquaBiquad(a, b, c, &x1, &x2, &x3, &x4);
            SolutionPrint(n, x1, x2, x3, x4);
            break;
        case 0:
            printf_s("Tam biet!\n");
            break;
        default:
            printf_s("Lua chon khong hop le.\n");
        }
    } while (choice != 0);

    return 0;
}