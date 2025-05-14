int calcularMCD(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int calcularMCM(int a, int b) {
    int mcd = calcularMCD(a, b);
    return (a * b) / mcd;
}