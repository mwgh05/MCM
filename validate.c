#include "back.c"

int processMCM(int num1, int num2, char *result) {
    if (num1 > 0 && num2 > 0) {
        int mcm = calcularMCM(num1, num2);
        return mcm;
    } else {
        return -1;
    }
}