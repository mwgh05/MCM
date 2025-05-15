#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "back.c"

int esNumeroValido(const char *str) {
    if (str == NULL || strlen(str) == 0) {
        return -3;
    }

    int start = 0;
    if (str[0] == '-') {
        start = 1;
    }

    for (int i = start; str[i]; i++) {
        if (!isdigit((unsigned char)str[i])) {
            return 0;
        }
    }

    return 1;
}

int processMCM(const char *input1, const char *input2, char *result) {
    if (strlen(input1) == 0 || strlen(input2) == 0) {
        return -3;
    }

    if (!esNumeroValido(input1) || !esNumeroValido(input2)) {
        return -2;
    }

    int num1 = atoi(input1);
    int num2 = atoi(input2);

    if (num1 > 0 && num2 > 0) {
        int mcm = calcularMCM(num1, num2);
        return mcm;
    } else {
        return -1;
    }
}
